#pragma once

class Progression
{
private:
	double first;
	unsigned int second;
public:
	Progression(double, int);
	double element(int);
};