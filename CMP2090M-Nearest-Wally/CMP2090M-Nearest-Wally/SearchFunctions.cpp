#include "SearchFunctions.h"
#include "Result.h"
#include <iostream>
#include <vector>
#include <algorithm> 

void SearchFunctions::search(RefImage* wally, LargeImage* ref, const int size)
{
	std::vector<Result> results;
	std::cout << std::endl << "Finding Wally, this could take some time (aprox. 40-50 secs on Release)" << std::endl;
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

