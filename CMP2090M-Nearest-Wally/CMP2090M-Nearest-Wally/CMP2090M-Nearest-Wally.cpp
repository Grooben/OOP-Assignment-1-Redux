// CMP2090M-Nearest-Wally.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "IOFunctions.h"
#include <iostream>
#include <vector>
#include <thread>

int threadWrapper(const char *fileName)
{
	IO io;
	int rows = io.countRows(fileName);
	int cols = io.countCols(fileName);
	io.read_text(fileName, rows, cols);
	return 0;
}

int main()
{
    std::cout << "CMP2090M, Oliver Grooby, GRO16605155\n";

	const char *scenePath = "Cluttered_scene.txt";
	const char *wallyPath = "Wally_grey.txt";

	std::thread SceneGeneration(threadWrapper, scenePath);
	std::thread WallyGeneration(threadWrapper, wallyPath);

	SceneGeneration.join();
	WallyGeneration.join();
}
