#pragma once
#include "Pair.h"
#include <iostream>
#include <string>
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

Pair Pair::operator+(const Pair& p)
{
	return (Pair(this->first + p.first, this->second + p.second));
}

Pair Pair::operator-(const Pair& p)
{
	return (Pair(this->first - p.first, this->second - p.second));
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

void Pair::operator=(const Pair& p)
{
	this->first = p.first;
	this->second = p.second;
}

ostream& operator <<(ostream& stream, const Pair& p)
{
	stream << "(" << p.first << " : " << p.second << ")";
	return stream;
}

istream& operator >>(istream& stream, Pair& p)
{
	cout << "¬ведите число first и second через пробел: ";
	stream >> p.first >> p.second;
	return stream;
}

bool Pair::operator >(const Pair& p)
{
	if (this->first >= p.first && this->second > p.second)
	{
		return true;
	}
	if (this->first > p.first && this->second >= p.second)
	{
		return true;
	}
	return false;
}

bool Pair::operator <(const Pair& p)
{
	if (this->first <= p.first && this->second < p.second)
	{
		return true;
	}
	if (this->first < p.first && this->second <= p.second)
	{
		return true;
	}
	return false;
}