#pragma once
#include "RefImage.h"
#include "LargeImage.h"
class SearchFunctions
{
public:
	void search(RefImage * wally, LargeImage * ref, const int size);
private:
	// Linear searching function is only accesible to the SearchFunction class, as it is not needed out of scope.
	double linear(RefImage* wally, LargeImage* ref, int j, int k);
};

