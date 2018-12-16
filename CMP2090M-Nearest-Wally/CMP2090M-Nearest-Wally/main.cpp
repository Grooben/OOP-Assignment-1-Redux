// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "IOFunctions.h"
#include "Image.h"
#include <iostream>
#include <vector>
#include <thread>

void sceneThreadWrapper(const char *fileName, double *data, const int size);
void wallyThreadWrapper(const char *fileName, double *data, const int size);
//void threadWrapper(const char *fileName, const char *outFile);

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

	std::thread SceneGeneration(sceneThreadWrapper, scenePath, sceneTmp, sceneSize);
	std::thread WallyGeneration(wallyThreadWrapper, wallyPath, wallyTmp, wallySize);
	SceneGeneration.join();
	WallyGeneration.join();

	system("pause");
}

void sceneThreadWrapper(const char *fileName, double *data, const int size)
{
	IO io;
	std::cout << "Processing " << fileName << "..." << std::endl;
	io.read_text(fileName, data, size);
	Image* scene = new Image(data);
	std::cout << "First value of Scene is: " << scene->getImgValue(0) << std::endl;
}

void wallyThreadWrapper(const char *fileName, double *data, const int size)
{
	IO io;
	std::cout << "Processing " << fileName << "..." << std::endl;
	io.read_text(fileName, data, size);
	Image* wally = new Image(data);
	std::cout << "First value of Wally is: " << wally->getImgValue(0) << std::endl;
}

/*void threadWrapper(const char *fileName, const char *outFile)
{
	IO io;
	std::cout << "Processing " << fileName << "..." << std::endl;
	int rows = io.countRows(fileName);
	int cols = io.countCols(fileName);
	io.read_text(fileName, rows, cols, outFile);
}*/