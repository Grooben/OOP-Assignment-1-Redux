#pragma once
class Image
{
public:
	// Default constructor/destructor
	Image();
	~Image();

	//Constructors
	Image(int rows, int cols);

	int sizeR, sizeC, size;

protected:
	double* img;
};

