#pragma once

// Custom Struct to hold values from the linear search,
// so that they can be easily sorted and referred to.

struct Result
{
	double value; // Holds the SSD Value
	int x, y; // Holds X and Y values of the result
	Result()
	{
		this->value = 0.0;
		this->x = 0;
		this->y = 0;
	}
	Result(double value, int x, int y)
	{
		this->value = value;
		this->x = x;
		this->y = y;
	}
};

bool CompareResult(const Result &a, const Result &b) // Override sort function
{
	return a.value < b.value;
}
