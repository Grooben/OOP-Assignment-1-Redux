/* 
* Program: CMP2090M - Nearest Wally. A program to find a reference image in a larger image
* Author: Oliver Martin Grooby GRO16605155
*/

#include "IOFunctions.h"
#include "BaseImage.h"
#include "LargeImage.h"
#include "RefImage.h"
#include "SearchFunctions.h"
#include <iostream>
#include <vector>
#include <thread>

void sceneThreadWrapper(const char *fileName, double *data, const int size, LargeImage* scene);
void wallyThreadWrapper(const char *fileName, double *data, const int size, RefImage* wally);

int main()
{
    std::cout << "CMP2090M, Oliver Grooby, GRO16605155\n";

	// Some useful consts
	const char *scenePath = "Cluttered_scene.txt";
	const char *wallyPath = "Wally_grey.txt";

	const int scSzR = 768;
	const int scSzC = 1024;
	const int sceneSize = scSzR * scSzC;

	const int wlSzR = 36;
	const int wlSzC = 49;
	const int wallySize = wlSzR * wlSzC;

	// Create a temporary store to hold the images in, until copied to their respective objects
	double* sceneTmp = new double[sceneSize];
	double* wallyTmp = new double[wallySize];

	// Create "Image" Object using default (blank) constructors
	LargeImage* scene = new LargeImage();
	RefImage* wally = new RefImage();

	// Using threading to enhance execution time of the program
	std::thread SceneGeneration(sceneThreadWrapper, scenePath, sceneTmp, sceneSize, scene);
	std::thread WallyGeneration(wallyThreadWrapper, wallyPath, wallyTmp, wallySize, wally);
	SceneGeneration.join();
	WallyGeneration.join();

	// Peform sanity check on both objects
	std::cout << "First value of Scene is: " << scene->getImgValue(0) << std::endl;
	std::cout << "First value of Wally is: " << wally->getImgValue(0) << std::endl;

	system("pause"); // Pause after program execution
}

void sceneThreadWrapper(const char *fileName, double *data, const int size, LargeImage* scene)
{
	IO io; // Create IO object
	std::cout << "Processing " << fileName << "..." << std::endl;
	io.read_text(fileName, data, size); // Pass fileName, temporary array and array size to read_text function
	scene->setImage(data); // Use defined mutator to populate object with values
}

void wallyThreadWrapper(const char *fileName, double *data, const int size, RefImage* wally)
{
	// Wrapper function works as above
	IO io; 
	std::cout << "Processing " << fileName << "..." << std::endl;
	io.read_text(fileName, data, size);
	wally->setImage(data);
}
