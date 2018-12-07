#include "IOFunctions.h"
#include <iostream>
#include <fstream>
#include <string>


int IO::countRows(const char *fileName)
{
	int rowCount = 0;
	std::ifstream TxtFile(fileName);
	rowCount = std::count(std::istreambuf_iterator<char>(TxtFile), std::istreambuf_iterator<char>(), '\n');
	return rowCount;
}

int IO::countCols(const char *fileName)
{
	int colCount = 0;
	std::ifstream TxtFile(fileName);
	std::string tmp;
	std::getline(TxtFile, tmp);
	colCount = (std::count(tmp.begin(), tmp.end(), '\t') + std::count(tmp.begin(), tmp.end(), ' ') + 1) / 2;
	return colCount;
}

double* IO::read_text(const char *fileName, int sizeR, int sizeC, const char *outFile)
{
	double* data = new double[sizeR*sizeC];
	int i = 0;
	std::ifstream myfile(fileName);
	if (myfile.is_open())
	{

		while (myfile.good())
		{
			if (i > sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			// cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
	std::cout << "Done " << fileName << std::endl;
	return data;
}

// Overload that takes pre-exsisting array
void IO::read_text(const char * fileName, double * data, const int size)
{
	int i = 0;
	std::ifstream myfile(fileName);
	if (myfile.is_open())
	{

		while (myfile.good())
		{
			if (i > size - 1) break;
			myfile >> *(data + i);
			// cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
	std::cout << "Done " << fileName << std::endl;
}



// Converts a 1D array of doubles of size R*C to .pgm image of R rows and C Columns 
// and stores .pgm in filename
// Use Q = 255 for greyscale images and 1 for binary images.
void IO::write_pgm(const char *filename, double *data, int sizeR, int sizeC, int Q)
{

	int i, j;
	unsigned char *image;
	std::ofstream myfile;
	std::cout << "Outputting: " << filename << std::endl;
	image = (unsigned char *) new unsigned char[sizeR*sizeC];

	// convert the integer values to unsigned char

	for (i = 0; i < sizeR*sizeC; i++)
		image[i] = (unsigned char)data[i];

	myfile.open(filename, std::ios::out | std::ios::binary | std::ios::trunc);

	if (!myfile) {
		std::cout << "Can't open file: " << filename << std::endl;
		exit(1);
	}

	myfile << "P5" << std::endl;
	myfile << sizeC << " " << sizeR << std::endl;
	myfile << Q << std::endl;

	myfile.write(reinterpret_cast<char *>(image), (sizeR*sizeC) * sizeof(unsigned char));

	if (myfile.fail()) {
		std::cout << "Can't write image " << filename << std::endl;
		exit(0);
	}

	myfile.close();

	delete[] image;

}

