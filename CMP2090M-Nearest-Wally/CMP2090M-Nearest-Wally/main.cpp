/* 
* Program: CMP2090M - Nearest Wally. A program to find a reference image in a larger image
* Author: Oliver Martin Grooby GRO16605155
*/

// TODO: ROWS AND COLS ARE MIXED UP AND NEED TO BE FIXED!!

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
	double* sceneArr = new double[sceneSize];
	double* wallyArr = new double[wallySize];

	// Create "Image" Object using a defined size
	LargeImage* scene = new LargeImage(scSzR, scSzC);
	RefImage* wally = new RefImage(wlSzR, wlSzC);

	SearchFunctions sf; // Create SearchFunctions object

	// Using threading to enhance execution time of the program
	std::thread SceneGeneration(sceneThreadWrapper, scenePath, sceneArr, sceneSize, scene);
	std::thread WallyGeneration(wallyThreadWrapper, wallyPath, wallyArr, wallySize, wally);
	SceneGeneration.join();
	WallyGeneration.join();

	/*for (int i = 0; i <= wally->size - 1; i++)
	{
		std::cout << wally->getImgValue(i) << std::endl;
	}*/

	// Peform sanity check on both objects
	std::cout << "First value of Scene is: " << scene->getImgValue(0) << std::endl;
	std::cout << "47th value of Wally is: " << wally->getImgValue(48) << std::endl;


	std::cout << std::endl << wally->getImgValue(12, 1); // This appears to work best with scene but not wally - Investigate.

	sf.linearSearch(wally, scene);

	// Delete pointers before exiting
	delete scene;
	delete wally;

	//system("pause"); // Pause after program execution
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
