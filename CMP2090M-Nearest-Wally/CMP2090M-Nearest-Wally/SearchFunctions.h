#pragma once
#include "RefImage.h"
#include "LargeImage.h"
class SearchFunctions
{
public:
	void nearestNeighbour(BaseImage wally, BaseImage ref);
	void linearSearch(RefImage* wally, LargeImage* ref, const int size);
};

