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
	~Pair() {}
	void operator - (const Pair&);
	void operator + (const int&);
	void operator + (const double&);
	void operator = (const Pair&);
	friend ostream& operator << (ostream&, const Pair&);
	friend istream& operator >> (istream&, Pair&);
};

Pair::Pair()
{
	this->first = 0;
	this->second = 0.0;
}

Pair::Pair(int first, double second)
{
	this->first = first;
	this->second = second;
}

Pair::Pair(const Pair& other)
{
	this->first = other.first;
	this->second = other.second;
}

void Pair::operator-(const Pair& other)
{
	this->first -= other.first;
	this->second -= other.second;
}

void Pair::operator+(const int& x)
{
	this->first += x;
}

void Pair::operator+(const double& x)
{
	this->second += x;
}

void Pair::operator=(const Pair& other)
{
	this->first = other.first;
	this->second = other.second;
}

ostream& operator<<(ostream& stream, const Pair& pair)
{
	stream << "(" << pair.first << ":" << pair.second << ")";
	return stream;
}

istream& operator>>(istream& stream, Pair& pair)
{
	int first; double second;
	stream >> first >> second;
	pair.first = first;
	pair.second = second;
	return stream;
}