#pragma once
#include "Print.h"

Print::Print()
{
	this->Author = "noAuthor";
	this->Name = "NoName";
}

Print::Print(string author, string name)
{
	this->Author = author;
	this->Name = name;
}

Print::Print(const Print& other)
{
	this->Author = other.Author;
	this->Name = other.Name;
}

void Print::Show(bool names = false)
{
	if (!names)
	{
		cout << "�����: " << this->Author 
			<< "\n��������: " << this->Name << "\n\n";
	}
	else
	{
		cout << "��������: " << this->Name << "\n\n";
	}
}

void Print::Input()
{
	cout << "\n������� ������\n";
	cout << "�����: ";
	cin.seekg(cin.eof());
	getline(cin, this->Author);
	cout << "��������: ";
	cin.seekg(cin.eof());
	getline(cin, this->Name);
}

Print& Print::operator=(const Print& other_Print)
{
	if (&other_Print == this)
	{
		return *this;
	}
	this->Author = other_Print.Author;
	this->Name = other_Print.Name;
	return *this;
}