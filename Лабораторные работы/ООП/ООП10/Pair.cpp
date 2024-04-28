#pragma once
#include "Pair.h"
using namespace std;

Pair::Pair() 
{
	this->first = 0;
	this->second = 0;
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

void Pair::Print() 
{
	cout << "(" << this->first << " : " << this->second << ")\n";
}

Pair Pair::operator+(Pair& pair)
{
	return (Pair(this->first + pair.first, this->second + pair.second));
}

Pair Pair::operator-(const Pair& pair) 
{
	return (Pair(this->first - pair.first, this->second - pair.second));
}

Pair Pair::operator+(const int& x) 
{
	return (Pair(this->first + x, this->second));
}

Pair Pair::operator+(const double& y) 
{
	return (Pair(this->first, this->second + y));
}

void Pair::setFirst(const int& x) 
{
	this->first = x;
}

void Pair::setSecond(const double& y) 
{
	this->second = y;
}

int Pair::getFirst() 
{
	return this->first;
}

double Pair::getSecond() 
{
	return this->second;
}

void Pair::operator=(const Pair& pair)
{
	this->first = pair.first;
	this->second = pair.second;
}

ostream& operator <<(ostream& stream, const Pair& pair)
{
	stream << pair.first << " : " << pair.second;
	return stream;
}
istream& operator >>(istream& stream, Pair& pair)
{
	cout << "¬ведите число first и second через пробел: ";
	stream >> pair.first >> pair.second;
	return stream;
}

bool Pair::operator >(const Pair& pair)
{
	if (this->first < pair.first)
	{
		return false;
	}
	if (this->first == pair.first && this->second < pair.second)
	{
		return false;
	}
	return true;
}

bool Pair::operator <(const Pair& pair)
{
	if (this->first > pair.first)
	{
		return false;
	}
	if (this->first == pair.first && this->second > pair.second)
	{
		return false;
	}
	return true;
}

fstream& operator<<(fstream& stream, Pair& pair)
{
	stream << pair.first << "\n" << pair.second << "\n";
	return stream;
}

fstream& operator>>(fstream& stream, Pair& pair)
{
	stream >> pair.first;
	stream >> pair.second;
	return stream;
}