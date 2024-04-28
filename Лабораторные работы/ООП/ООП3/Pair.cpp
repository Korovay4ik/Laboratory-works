#pragma once
#include <iostream>
using namespace std;
#include "Pair.h"

Pair::Pair()
{
	cout << "\n����� ������������ ��� ���������� ��� ������� " << this << endl;
	this->first = 0;
	this->second = 0.0;
}

Pair::Pair(int first, double second)
{
	cout << "����� ������������ � ����������� ��� ������� " << this << endl;
	this->first = first;
	this->second = second;
}

Pair::Pair(const Pair& other)
{
	cout << "\n����� ������������ ����������� ��� ������� " << this << endl;
	this->first = other.first;
	this->second = other.second;
}

Pair::~Pair()
{
	cout << "����� ����������� ��� ������� " << this << endl;
}

void Pair::Print() 
{
	cout << "(" << this->first << ":" << this->second << ")\n";
}

void Pair::operator-(const Pair& other)
{
	cout << "\n����� ��������� ��������� ��� ������� " << this << endl;
	this->first -= other.first;
	this->second -= other.second;
}

void Pair::operator+(const int&x)
{
	cout << "\n����� ��������� ������������  int ��� ������� " << this << endl;
	this->first += x;
}

void Pair::operator+(const double& x)
{
	cout << "\n����� ��������� ������������ double ��� ������� " << this << endl;
	this->second += x;
}

void Pair::operator=(const Pair& other)
{
	cout << "\n����� ��������� ������������ ��� �������" << this << endl;
	this->first = other.first;
	this->second = other.second;
}

ostream& operator<<(ostream& stream, const Pair& pair)
{
	cout << "����� ��������� ������ ��� ������� " << &pair << endl;
	stream << "(" << pair.first << ":" << pair.second << ")";
	return stream;
}

istream& operator>>(istream& stream, Pair& pair)
{
	cout << "����� ��������� ����� ��� ������� " << &pair << endl;
	int first; double second;
	stream >> first >> second;
	pair.first = first;
	pair.second = second;
	return stream;
}