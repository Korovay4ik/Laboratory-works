#pragma once
#include <iostream>
using namespace std;
#include "Object.h"
#include "Print.h"
#include "Magazin.h"

class Vector
{
protected:
	Object** begin;
	int size;
	int current_position;
public:
	Vector();
	Vector(int);
	~Vector();
	void Add();
	void Del();
	void print(bool);
	void create(int);
	void resize(int);
	int operator() ();
	friend ostream& operator << (ostream&, const Vector&);
};