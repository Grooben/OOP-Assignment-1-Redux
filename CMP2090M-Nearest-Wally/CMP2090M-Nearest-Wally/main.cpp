// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "IOFunctions.h"
#include <iostream>
#include <vector>
#include <thread>

//void threadWrapper(const char *fileName, const char *outFile);
void threadWrapper(const char *fileName, double *data, const int size);


int main()
{
    std::cout << "CMP2090M, Oliver Grooby, GRO16605155\n";

	// Some useful consts
	const char *scenePath = "Cluttered_scene.txt";
	const char *wallyPath = "Wally_grey.txt";
	const int sceneSize = 748 * 1024;
	const int wallySize = 36 * 49;

	double* sceneTmp = new double[sceneSize];
	double* wallyTmp = new double[wallySize];

	std::thread SceneGeneration(threadWrapper, scenePath, sceneTmp, sceneSize);
	std::thread WallyGeneration(threadWrapper, wallyPath, wallyTmp, wallySize);
	SceneGeneration.join();
	WallyGeneration.join();
}

/*void threadWrapper(const char *fileName, const char *outFile)
{
	IO io;
	std::cout << "Processing " << fileName << "..." << std::endl;
	int rows = io.countRows(fileName);
	int cols = io.countCols(fileName);
	io.read_text(fileName, rows, cols, outFile);
}*/

void threadWrapper(const char *fileName, double *data, const int size)
{
	IO io;
	std::cout << "Processing " << fileName << "..." << std::endl;
	io.read_text(fileName, data, size);
}
