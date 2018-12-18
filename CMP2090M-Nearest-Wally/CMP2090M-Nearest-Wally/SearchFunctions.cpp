#include "SearchFunctions.h"
#include <iostream>

void SearchFunctions::nearestNeighbour(BaseImage wally, BaseImage ref)
{
	// NNS Logic to be inserted here
}

void SearchFunctions::search(RefImage* wally, LargeImage* ref, const int size)
{
	for (int j = 0; j < ref->sizeR - wally->sizeR; j++)
	{
		for (int k = 0; k < ref->sizeC - wally->sizeC; k++)
		{
			linear(j, k);
		}
	}

}

double SearchFunctions::linear(int j, int k)
{
	int something;
	return something;
}

