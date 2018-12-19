#include "SearchFunctions.h"
#include "Result.h"
#include "Matrix.h"
#include "IOFunctions.h"
#include <iostream>
#include <vector>
#include <algorithm> 

void SearchFunctions::search(RefImage* wally, LargeImage* ref, const int size)
{
	std::vector<Result> results;
	std::cout << std::endl << "Finding Wally, this could take some time..." << std::endl;
	for (int k = 0; k < ref->sizeR - wally->sizeR; k+=6)
	{
		for (int j = 0; j < ref->sizeC - wally->sizeC; j+=6)
		{
			results.push_back(Result::Result(linear(wally, ref, j, k), j, k));
		}
	}
	std::cout << "Done! Sorting results..." << std::endl << std::endl;
	std::sort(results.begin(), results.end(), CompareResult);
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Rank " << i + 1 <<" SSD Value: " << results[i].value << " "  <<
			"X: "<< results[i].x << " Y: " << results[i].y << std::endl;
	}
	Matrix mt;
	mt.shadeWallyBorder(ref->getImage(), wally->sizeR, wally->sizeC, ref->sizeC, results[0].y, results[0].x);
	for (int i = 10; i >= 1; i--)
	{
		mt.shadeWallyBorder(ref->getImage(), wally->sizeR, wally->sizeC, ref->sizeC, results[i].y, results[i].x, true);
	}
		
	IO io;
	io.write_pgm("output.pgm", ref->getImage(),
		ref->sizeR, ref->sizeC, 255);
}

double SearchFunctions::linear(RefImage* wally, LargeImage* ref, int j, int k)
{
	double sosd = 0.0;
	for (int x = j; x < j + wally->sizeC; x++)
	{
		for (int y = k; y < k + wally->sizeR; y++)
		{
			if (wally->getImgValue(x - j, y - k) != 255.0)
			{
				sosd += std::pow(wally->getImgValue(x - j, y - k) - ref->getImgValue(x, y), 2.0);
			}
		}
	}
	return sosd;
}

