#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pair 
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair() {}
	void Print();

	Pair operator+(Pair&);
	Pair operator-(const Pair&);
	Pair operator+(const int&);
	Pair operator+(const double&);

	void setFirst(const int&);
	void setSecond(const double&);
	int getFirst();
	double getSecond();
	void operator=(const Pair&);
	friend ostream& operator <<(ostream&, const Pair&);
	friend istream& operator >>(istream&, Pair&);
	bool operator >(const Pair&);
	bool operator <(const Pair&);
	friend fstream& operator<<(fstream&, Pair&);
	friend fstream& operator>>(fstream&, Pair&);
};