#pragma once

class IO 
{
public:
	// Row counting functions (not used in current implementation)
	int countRows(const char *fileName);
	int countCols(const char *fileName);

	// File access functions with overloaded read_text function
	double* read_text(const char *fileName, int sizeR, int sizeC, const char *outFile);
	void read_text(const char *fileName, double* data, const int size);
	void write_pgm(const char *filename, double *data, int sizeR, int sizeC, int Q);

};

