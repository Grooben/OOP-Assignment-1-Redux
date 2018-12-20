#include "Matrix.h"

// Array Manipulation Class

double Matrix::Get2DLocation(LargeImage* data, int x, int y)
{
	// Allows given 1D array as part of an object to be traversed as a 2D array
	return data->getImgValue(x + (y * data->sizeC));
}

double Matrix::Get2DLocation(RefImage* data, int x, int y)
{
	return data->getImgValue(x + (y * data->sizeC));
}

double* Matrix::shadeBorder(double* data, int refR, int refC, int sizeC, int resRow, int resCol) {
	// Function to generate a border around Wally's location
	for (int rowCount = resRow; rowCount <= resRow + refR; rowCount++) { // Shades horizontally from the starting point of the location to (start location + sizeR of the reference image)
		for (int colCount = resCol; colCount <= resCol + refC; colCount++) {

			if (rowCount == resRow || rowCount == resRow + refR) { // Shades vertically from the starting point of the location to (start location + sizeC of the reference image)
				for (int x = 0; x < 2; x++) { // Border thickness is 2 pixels
					data[sizeC * (rowCount - x) + (colCount - x)] = 1; // Overrides values of rows with a value of 1
				}
			}

			if (colCount == resCol || colCount == resCol + refC) { // Shades vertically from the starting point of the location to (start location + sizeC of the reference image)
				for (int x = 0; x < 2; x++) { // Border thickness is 2 pixels
					data[sizeC * (rowCount - x) + (colCount - x)] = 1; // Overrides values of rows with a value of 1
				}
			}
		}
	}
	return data; // Returns manipulated array back to calling function, this array can now be used in conjection with the give write_file fuction
}

double * Matrix::shadeBorder(double * scene, int R, int wallyC, int sceneC, int WallyLocR, int WallyLocC, bool nth)
{
	// Overloaded function that shows nth closest results with a slightly lighter border
	for (int rCnt = WallyLocR; rCnt <= WallyLocR + R; rCnt++) { 
		for (int cCnt = WallyLocC; cCnt <= WallyLocC + wallyC; cCnt++) {

			if (rCnt == WallyLocR || rCnt == WallyLocR + R) { 
				for (int x = 0; x < 2; x++) {
					scene[sceneC * (rCnt - x) + (cCnt - x)] = 65;
				}
			}

			if (cCnt == WallyLocC || cCnt == WallyLocC + wallyC) { 
				for (int x = 0; x < 2; x++) {
					scene[sceneC * (rCnt - x) + (cCnt - x)] = 50;
				}
			}
		}
	}
	return scene;
}

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}
