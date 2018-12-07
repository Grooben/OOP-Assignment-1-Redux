#pragma once

class IO 
{
public:

	int countRows(const char *fileName);
	int countCols(const char *fileName);

	double* read_text(const char *fileName, int sizeR, int sizeC, const char *outFile);
	void read_text(const char *fileName, double* data, const int size);
	void write_pgm(const char *filename, double *data, int sizeR, int sizeC, int Q);

};

