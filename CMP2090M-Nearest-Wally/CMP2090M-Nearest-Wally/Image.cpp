#include "Image.h"

// Accessor & Mutator Functions below.
// Get the Entire Image Arr:
double* Image::getImage()
{
	return img;
}
// Set the entire Image Arr:
void Image::setImage(double* image)
{
	this->img = image;
}
// Set an individual value in the image array, by passing the location of the value,
// and the value it replaces.
void Image::setImgValue(int loc, double indv)
{
	img[loc] = indv;
}

double Image::getImgValue(int loc)
{
	return this->img[loc];
}

// Constructors below.
// Default constructor
Image::Image() { }

// Constructor that takes rows & cols to initialise an array of doubles.
Image::Image(int rows, int cols)
{
	this->sizeR = rows;
	this->sizeC = cols;
	this->size = sizeR * sizeC;

	this->img = new double[size];

}

Image::Image(double * data)
{
	this->img = data;
}

// Default Destructor
Image::~Image()
{
	delete[] img;
}
