// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "IOFunctions.h"
#include "Image.h"
#include "SearchFunctions.h"
#include <iostream>
#include <vector>
#include <thread>

void sceneThreadWrapper(const char *fileName, double *data, const int size, Image* scene);
void wallyThreadWrapper(const char *fileName, double *data, const int size, Image* wally);

int main()
{
    std::cout << "CMP2090M, Oliver Grooby, GRO16605155\n";

	// Some useful consts
	const char *scenePath = "Cluttered_scene.txt";
	const char *wallyPath = "Wally_grey.txt";
	const int sceneSize = 768 * 1024;
	const int wallySize = 36 * 49;

	double* sceneTmp = new double[sceneSize];
	double* wallyTmp = new double[wallySize];

	Image* scene = new Image();
	Image* wally = new Image();

	std::thread SceneGeneration(sceneThreadWrapper, scenePath, sceneTmp, sceneSize, scene);
	std::thread WallyGeneration(wallyThreadWrapper, wallyPath, wallyTmp, wallySize, wally);
	SceneGeneration.join();
	WallyGeneration.join();

	std::cout << "First value of Scene is: " << scene->getImgValue(0) << std::endl;
	std::cout << "First value of Wally is: " << wally->getImgValue(0) << std::endl;

	system("pause");
}

void sceneThreadWrapper(const char *fileName, double *data, const int size, Image* scene)
{
	IO io;
	std::cout << "Processing " << fileName << "..." << std::endl;
	io.read_text(fileName, data, size);
	scene->setImage(data);
}

void wallyThreadWrapper(const char *fileName, double *data, const int size, Image* wally)
{
	IO io;
	std::cout << "Processing " << fileName << "..." << std::endl;
	io.read_text(fileName, data, size);
	wally->setImage(data);
}
