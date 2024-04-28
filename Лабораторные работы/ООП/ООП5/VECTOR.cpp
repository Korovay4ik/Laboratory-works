#pragma once
#include "VECTOR.h"

Vector::Vector()
{
	this->begin = 0;
	this->size = 0;
	this->current_position = 0;
}

Vector::Vector(int size)
{
	this->begin = new Object * [size];
	this->size = size;
	this->current_position = 0;
}

Vector::~Vector()
{
	if (begin != 0)
	{
		delete[] begin;
	}
	begin = 0;
}

void Vector::Add(Object* ptr)
{
	if (current_position < size)
	{
		begin[current_position] = ptr;
		current_position++;
	}
}

ostream& operator<<(ostream& stream, const Vector& vector)
{
	if (vector.size == 0)
	{
		cout << "Пусто =(\n";
	}
	else 
	{
		Object** ptr = vector.begin;
		for (int i = 0; i < vector.current_position; i++)
		{
			(*ptr)->Show();
			ptr++;
		}
	}
	return stream;
}
