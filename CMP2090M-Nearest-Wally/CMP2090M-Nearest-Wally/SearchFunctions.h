#pragma once
#include "RefImage.h"
#include "LargeImage.h"
class SearchFunctions
{
public:
	void search(RefImage * wally, LargeImage * ref, const int size);
private:
	double linear(RefImage* wally, LargeImage* ref, int j, int k);
};

