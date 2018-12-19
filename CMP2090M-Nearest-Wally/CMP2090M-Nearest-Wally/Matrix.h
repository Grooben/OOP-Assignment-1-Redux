#pragma once
#include "LargeImage.h"
#include "RefImage.h"
class Matrix
{
public:
	Matrix(int sizeR, int sizeC, LargeImage* image);
	Matrix(int sizeR, int sizeC, RefImage* image);
	double * shadeWallyBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol);
	Matrix();
	~Matrix();

private:
	int _X, _Y;
	double _data;
};

