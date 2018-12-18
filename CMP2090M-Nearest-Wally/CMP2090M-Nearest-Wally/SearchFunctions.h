#pragma once
#include "RefImage.h"
#include "LargeImage.h"
class SearchFunctions
{
public:
	void nearestNeighbour(BaseImage wally, BaseImage ref);
	void search(RefImage * wally, LargeImage * ref, const int size);
private:
	double linear(int j, int k);
};

