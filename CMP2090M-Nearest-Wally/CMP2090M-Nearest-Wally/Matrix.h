#pragma once
#include "LargeImage.h"
#include "RefImage.h"
class Matrix
{
public:
	double Get2DLocation(LargeImage * data, int x, int y);
	double Get2DLocation(RefImage * data, int x, int y);
	double * shadeWallyBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol);
	double * shadeWallyBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol, bool nth);
	Matrix();
	~Matrix();
};
