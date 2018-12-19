#pragma once
#include "LargeImage.h"
#include "RefImage.h"
class Matrix
{
public:
	// Functions to get location from a 1D space using 2D Co-ords
	double Get2DLocation(LargeImage * data, int x, int y);
	double Get2DLocation(RefImage * data, int x, int y);
	// Shading functions
	double * shadeBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol);
	double * shadeBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol, bool nth);
	Matrix();
	~Matrix();
};
