#pragma once
class BaseImage
{
public:
	//Accessor & Mutator functions
	double* getImage();
	void setImage(double* img);
	void setImgValue(int loc, double indv);
	double getImgValue(int loc);
	double getImgValue(int x, int y);

	// Default constructor/destructor
	BaseImage();
	~BaseImage();

	//Constructors
	BaseImage(int rows, int cols);
	BaseImage(double* data);
	
	int sizeR, sizeC, size;

protected:
	double* img;
};

