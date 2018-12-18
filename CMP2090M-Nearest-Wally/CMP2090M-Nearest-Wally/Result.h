#pragma once

struct Result
{
	double value;
	int x, y;
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

bool CompareResult(const Result &a, const Result &b)
{
	return a.value < b.value;
}
