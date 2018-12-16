#pragma once
class Image
{
public:
	//Accessor & Mutator functions
	double* getImage();
	void setImage(double* img);
	void setImgValue(int loc, double indv);
	double getImgValue(int loc);
	// Default constructor/destructor
	Image();
	~Image();

	//Constructors
	Image(int rows, int cols);
	Image(double* data);
	
	int sizeR, sizeC, size;

protected:
	double* img;
};

