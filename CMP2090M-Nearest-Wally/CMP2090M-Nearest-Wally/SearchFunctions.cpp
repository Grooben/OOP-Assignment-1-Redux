#include "SearchFunctions.h"
#include "Result.h"
#include "Matrix.h"
#include "IOFunctions.h"
#include <iostream>
#include <vector>
#include <algorithm> 

void SearchFunctions::search(RefImage* wally, LargeImage* ref, const int size)
{
	std::vector<Result> results; // Create a vector of type Results (custom struct found in "Result.h"
	std::cout << std::endl << "Finding Wally, this could take some time..." << std::endl;
	for (int k = 0; k < ref->sizeR - wally->sizeR; k+=6) // Traverse 6 rows of the scene
	{
		for (int j = 0; j < ref->sizeC - wally->sizeC; j+=6) // Traverse 6 columns of the scene
		{
			results.push_back(Result::Result(linear(wally, ref, j, k), j, k)); // Push comparison results to results vector
		}
		// We traverse by 6 everytime, as I found this to be a good compromise between compute time and accuracy, 
		// IE results didn't change while using this more selective approach
	}
	std::cout << "Done! Sorting results..." << std::endl << std::endl;
	std::sort(results.begin(), results.end(), CompareResult);
	int resultCount = results.size();
	std::cout << "How many N-Best values should be listed? " << resultCount << " were found! 12 are selectable" << std::endl;
	int nBestCount;
	std::cin >> nBestCount;
	if (nBestCount < 12)
	{
		std::cout << "Please select 12 or less." << std::endl;
		std::cin >> nBestCount;
	}
	for (int i = 0; i < nBestCount; i++)
	{
		std::cout << "Rank " << i + 1 <<" SSD Value: " << results[i].value << " "  <<
			"X: "<< results[i].x << " Y: " << results[i].y << std::endl;
	}
	Matrix mt; // Create instance of Matrix for maniuplation of array
	mt.shadeBorder(ref->getImage(), wally->sizeR, wally->sizeC, ref->sizeC, results[0].y, results[0].x); // Shade the border of wally's location in black
	for (int i = 1; i <= nBestCount; i++) // Shade the next 9 best values
	{
		mt.shadeBorder(ref->getImage(), wally->sizeR, wally->sizeC, 
			ref->sizeC, results[i].y, results[i].x, true); // Uses overloaded shade function to produce a lighter border
	}
		
	IO io; // Create instance of IO to write .pgm file out
	io.write_pgm("output.pgm", ref->getImage(),
		ref->sizeR, ref->sizeC, 255);
}

double SearchFunctions::linear(RefImage* wally, LargeImage* ref, int j, int k)
{
	// Function to perform a linear search for wally, using wally sized chunks from the image
	double ssdValue = 0.0; // Create a double for the SSD Value
	for (int x = j; x < j + wally->sizeC; x++) // Traverse the column size of wally along the scene's columns
	{
		for (int y = k; y < k + wally->sizeR; y++) // Traverse the row size of wally along the scene's rows
		{
			if (wally->getImgValue(x - j, y - k) != 255.0) // Ignore any white values, as there is no white on wally himself
			{
				ssdValue += std::pow(wally->getImgValue(x - j, y - k) - ref->getImgValue(x, y), 2.0); // Calculate the SSD value between wally and the scene chunk
			}
		}
	}
	return ssdValue; // Returns the SSD Value to be pushed into the results vector
}

