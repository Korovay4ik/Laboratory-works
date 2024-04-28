#pragma once
#include <iostream>
using namespace std;
#include "Pair.h"

Pair::Pair()
{
	cout << "\nВызов конструктора без параметров для объекта " << this << endl;
	this->first = 0;
	this->second = 0.0;
}

Pair::Pair(int first, double second)
{
	cout << "Вызов конструктора с параметрами для объекта " << this << endl;
	this->first = first;
	this->second = second;
}

Pair::Pair(const Pair& other)
{
	cout << "\nВызов конструктора копирования для объекта " << this << endl;
	this->first = other.first;
	this->second = other.second;
}

Pair::~Pair()
{
	cout << "Вызов дуструктора для объекта " << this << endl;
}

void Pair::Print() 
{
	cout << "(" << this->first << ":" << this->second << ")\n";
}

void Pair::operator-(const Pair& other)
{
	cout << "\nВызов оператора вычитания для объекта " << this << endl;
	this->first -= other.first;
	this->second -= other.second;
}

void Pair::operator+(const int&x)
{
	cout << "\nВызов оператора суммирования  int для объекта " << this << endl;
	this->first += x;
}

void Pair::operator+(const double& x)
{
	cout << "\nВызов оператора суммирования double для объекта " << this << endl;
	this->second += x;
}

void Pair::operator=(const Pair& other)
{
	cout << "\nВызов оператора присваивания для объекта" << this << endl;
	this->first = other.first;
	this->second = other.second;
}

ostream& operator<<(ostream& stream, const Pair& pair)
{
	cout << "Вызов оператора вывода для объекта " << &pair << endl;
	stream << "(" << pair.first << ":" << pair.second << ")";
	return stream;
}

istream& operator>>(istream& stream, Pair& pair)
{
	cout << "Вызов оператора ввода для объекта " << &pair << endl;
	int first; double second;
	stream >> first >> second;
	pair.first = first;
	pair.second = second;
	return stream;
}