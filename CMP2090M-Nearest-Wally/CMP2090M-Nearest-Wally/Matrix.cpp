#include "Matrix.h"



Matrix::Matrix(int sizeR, int sizeC, LargeImage * image)
{

}

Matrix::Matrix(int sizeR, int sizeC, RefImage * image)
{

}

double* Matrix::shadeWallyBorder(double* sceneDoubles, int wallyRows, int wallyCols, int sceneCols, int WallyFoundRow, int WallyFoundCol) {
	/*
	 This function takes the first row and column of the chunk of the cluttered scene in which Wally has been found as input (WallyFoundRow and WallyFoundCol) and, using that as a starting location,
	 changes the original array of doubles returned from ReadWriteFunctions.cpp's read_text function so that the pixels bordering the section of the ClutteredScene in which Wally has been found
	 are coloured black. The border is 4 pixels thick, hence the pixel-changing for-loops terminating when x is incremented 4 times, moving the pixel selector either across or vertically
	 4 times.

	*/

	/*for (int rowCount = WallyFoundRow; rowCount <= WallyFoundRow + wallyRows; rowCount++) { //colours horizontally from the starting point to the starting point + the amount of rows in the ref image (49)
		for (int colCount = WallyFoundCol; colCount <= WallyFoundCol + wallyCols; colCount++) {//colours vertically from the starting point to the starting point + the amount of columns in the ref image (36)

			if (rowCount == WallyFoundRow || rowCount == WallyFoundRow + wallyRows) { //Highlights Rows with a border 4 pixels high
				for (int x = 0; x < 4; x++) {
					_data[sceneCols * (rowCount - x) + (colCount - x)] = 1;
				}
			}

			if (colCount == WallyFoundCol || colCount == WallyFoundCol + wallyCols) { //Highlights Columns with a border 4 pixels wide
				for (int x = 0; x < 4; x++) {
					_data[sceneCols * (rowCount - x) + (colCount - x)] = 1;
				}
			}
		}
	}*/
	return sceneDoubles; //returns a new array of doubles to be passed into ReadWriteFunctions.cpp's WritePGM method, creating a PGM image in which the selected area is highlighted
}

Matrix::Matrix()
{
}


Matrix::~Matrix()
{
}
