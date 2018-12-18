#include "BaseImage.h"

// Accessor & Mutator Functions below.
// Get the Entire Image Arr:
double* BaseImage::getImage()
{
	return img;
}
// Set the entire Image Arr:
void BaseImage::setImage(double* image)
{
	this->img = image;
}
// Set an individual value in the image array, by passing the location of the value,
// and the value it replaces.
void BaseImage::setImgValue(int loc, double indv)
{
	img[loc] = indv;
}

double BaseImage::getImgValue(int loc)
{
	return this->img[loc];
}


double BaseImage::getImgValue(int row, int col)
{
	// NB: Image pixel co-ords start at 0,0
	// ROW = X, COL = Y
	return this->img[row + (col * this->sizeR)];
}

// Constructors below.
// Default constructor
BaseImage::BaseImage() { }

// Constructor that takes rows & cols to initialise an array of doubles.
BaseImage::BaseImage(const int rows, const int cols)
{
	this->sizeR = rows;
	this->sizeC = cols;
	this->size = sizeR * sizeC;
	// TODO: Investigate hard copy method
}

BaseImage::BaseImage(double * data)
{
	this->img = data;
}

// Default Destructor
BaseImage::~BaseImage()
{
	delete[] img;
}
