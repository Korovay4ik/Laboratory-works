#pragma once
#include "Vector.h"

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

void Vector::Add()
{
	if (this->current_position < this->size)
	{
		Object* ptr;
		cout << "Объект какого класса?\n1) Print\n2) Magazin\n";
		int choice;
		do
		{
			cout << "Ваш выбор: ";
			cin >> choice;
		} while (choice < 1 && choice > 2);
		if (choice == 1)
		{
			Print* print = new Print;
			print->Input();
			cout << "\n";
			ptr = print;
			this->begin[this->current_position] = ptr;
			this->current_position++;
		}
		else if (choice == 2)
		{
			Magazin* magazin = new Magazin;
			magazin->Input();
			cout << "\n";
			ptr = magazin;
			this->begin[this->current_position] = ptr;
			this->current_position++;
		}
	}
	else
	{
		cout << "Больше некуда =(\n\n";
	}
}

void Vector::Del()
{
	if (current_position > 0)
	{
		this->current_position--;
	}
	else
	{
		cout << "Меньше некуда =(\n\n";
	}
}

void Vector::print(bool names = false)
{
	if (this->current_position == 0)
	{
		cout << "Пусто =(\n\n";
	}
	else
	{
		Object** ptr = this->begin;
		for (int i = 0; i < this->current_position; i++)
		{
			(*ptr)->Show(names);
			ptr++;
		}
	}
}

void Vector::create(int size)
{
	if (this->begin != 0) 
	{
		for (int i = 0; i < this->size; i++) 
		{
			delete this->begin[i];
		}
		delete[] this->begin;
	}
	this->begin = new Object * [size];
	this->size = size;
	this->current_position = 0;
}

void Vector::resize(int new_size)
{
	int temp_size = this->size;
	this->size = new_size;
	if (this->current_position != 0)
	{
		if (new_size < temp_size)
		{
			this->current_position--;
			for (int i = temp_size; i > new_size; i--)
			{
				if(this->current_position > 0)
				{
					delete begin[this->current_position];
					this->current_position--;
				}
			}
			if(this->size != 0)
			{
				this->current_position++;
			}
		}
	}
}

int Vector::operator() ()
{
	return this->size;
}
ostream& operator<<(ostream& stream, const Vector& vector)
{
	if (vector.current_position == 0)
	{
		cout << "Пусто =(\n\n";
	}
	else
	{
		Object** ptr = vector.begin;
		for (int i = 0; i < vector.current_position; i++)
		{
			(*ptr)->Show(false);
			ptr++;
		}
	}
	return stream;
}