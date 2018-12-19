#include "Matrix.h"


Matrix::Matrix()
{

}

Matrix::Matrix(double* inData)
{
	int size = sizeof(inData);
	for (int i = 0; i < size; i++)
	{
		this->_data[i] = inData[i];
	}
}

double Matrix::Get2DLocation(int x, int y, int cols)
{
	return this->_data[x + (y * cols)];
}

double* Matrix::shadeWallyBorder(double* data, int refR, int refC, int sizeC, int resRow, int resCol) {

	for (int rowCount = resRow; rowCount <= resRow + refR; rowCount++) {
		for (int colCount = resCol; colCount <= resCol + refC; colCount++) {

			if (rowCount == resRow || rowCount == resRow + refR) { // Overrides values of rows with a value of 1
				for (int x = 0; x < 2; x++) {
					data[sizeC * (rowCount - x) + (colCount - x)] = 1;
				}
			}

			if (colCount == resCol || colCount == resCol + refC) { // Overrides values of columns with a value of 1
				for (int x = 0; x < 2; x++) {
					data[sizeC * (rowCount - x) + (colCount - x)] = 1;
				}
			}
		}
	}
	return data; //returns a new array of doubles to be passed into ReadWriteFunctions.cpp's WritePGM method, creating a PGM image in which the selected area is highlighted
}

double * Matrix::shadeWallyBorder(double * sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol, bool nth)
{
	// Overloaded function that shows nth closest results with a slightly lighter border
	for (int rowCount = WallyFoundRow; rowCount <= WallyFoundRow + wallyRows; rowCount++) { 
		for (int colCount = WallyFoundCol; colCount <= WallyFoundCol + wallyCols; colCount++) {

			if (rowCount == WallyFoundRow || rowCount == WallyFoundRow + wallyRows) { 
				for (int x = 0; x < 2; x++) {
					sceneDoubles[sceneCols * (rowCount - x) + (colCount - x)] = 65;
				}
			}

			if (colCount == WallyFoundCol || colCount == WallyFoundCol + wallyCols) { 
				for (int x = 0; x < 2; x++) {
					sceneDoubles[sceneCols * (rowCount - x) + (colCount - x)] = 50;
				}
			}
		}
	}
	return sceneDoubles; //returns a new array of doubles to be passed into ReadWriteFunctions.cpp's WritePGM method, creating a PGM image in which the selected area is highlighted
}

Matrix::~Matrix()
{
}
