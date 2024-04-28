#pragma once

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	void Print();
	void operator - (const Pair&);
	void operator + (const int&);
	void operator + (const double&);
	void operator = (const Pair&);
	friend ostream& operator << (ostream&, const Pair&);
	friend istream& operator >> (istream&, Pair&);
};