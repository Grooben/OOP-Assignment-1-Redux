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
	std::cout << "CMP2090M, Oliver Grooby, GRO16605155" << std::endl;

	// Some useful consts
	const char *scenePath = "Cluttered_scene.txt";
	const char *wallyPath = "Wally_grey.txt";
	const int scSzR = 768;
	const int scSzC = 1024;
	const int sceneSize = scSzR * scSzC;
	const int wlSzR = 49;
	const int wlSzC = 36;
	const int wallySize = wlSzR * wlSzC;

	// Create a temporary store to hold the images in, until copied to their respective objects
	double* sceneArr = new double[sceneSize];
	double* wallyArr = new double[wallySize];

	// Create "Image" Object using a defined size
	LargeImage* scene = new LargeImage(scSzR, scSzC);
	RefImage* wally = new RefImage(wlSzR, wlSzC);

	SearchFunctions sf; // Create SearchFunctions object

	std::cout << std::endl << "Reading files into Memory..." << std::endl << std::endl;

	// Using threading to enhance execution time of the program
	std::thread SceneGeneration(sceneThreadWrapper, scenePath, sceneArr, sceneSize, scene);
	std::thread WallyGeneration(wallyThreadWrapper, wallyPath, wallyArr, wallySize, wally);
	SceneGeneration.join();
	WallyGeneration.join();

	// Enter main logic
	sf.search(wally, scene, wallySize);

	// Delete objects before exiting
	delete scene;
	delete wally;

	system("pause"); // Pause after program execution
}

void sceneThreadWrapper(const char *fileName, double *data, const int size, LargeImage* scene)
{
	IO io; // Create IO object
	io.read_text(fileName, data, size); // Pass fileName, temporary array and array size to read_text function
	scene->setImage(data); // Use defined mutator to populate object with values
}

void wallyThreadWrapper(const char *fileName, double *data, const int size, RefImage* wally)
{
	// Wrapper function works as above
	IO io; 
	io.read_text(fileName, data, size);
	wally->setImage(data);
}
