#pragma once
#include "LargeImage.h"
#include "RefImage.h"
class Matrix
{
public:
	Matrix(double * inData);
	double Get2DLocation(int x, int y, int cols);
	double * shadeWallyBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol);
	double * shadeWallyBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol, bool nth);
	Matrix();
	~Matrix();

private:
	int _X, _Y;
	double* _data;
};

