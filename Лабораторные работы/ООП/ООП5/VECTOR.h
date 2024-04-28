#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Object.h"

class Vector
{
private:
	Object** begin;
	int size, current_position;
public:
	Vector();
	Vector(int);
	~Vector();
	void Add(Object*);
	friend ostream& operator<<(ostream&, const Vector&);
};