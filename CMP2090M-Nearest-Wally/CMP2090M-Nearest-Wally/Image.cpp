#include "Image.h"

	

// Constructors below.
Image::Image(){ } // Default constructor

// Constructor that takes rows & cols to initialise an array of doubles.
Image::Image(int rows, int cols)
{
	this->sizeR = rows;
	this->sizeC = cols;
	this->size = sizeR * sizeC;

	this->img = new double[size];
}

Image::~Image()
{
}
