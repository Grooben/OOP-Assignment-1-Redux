#include "SearchFunctions.h"
#include <iostream>

void SearchFunctions::nearestNeighbour(BaseImage wally, BaseImage ref)
{
	// NNS Logic to be inserted here
}

void SearchFunctions::linearSearch(RefImage* wally, LargeImage* ref)
{
	int safeSizeC = ref->sizeC - 1;
	int safeSizeR = ref->sizeR;
	for (int i = 0; i < safeSizeR; i++)
	{
		if (ref->getImgValue(i, i) == wally->getImgValue(30, 1))
		{
			std::cout << "Made a match using I,I" << std::endl;
		}
	}
}

