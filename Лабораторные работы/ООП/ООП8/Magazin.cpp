#pragma once
#include "Magazin.h"

Magazin::Magazin() : Print()
{
	this->count_of_page = 0;
}

Magazin::Magazin(string author, string name, int pages) : Print(author, name)
{
	this->count_of_page = pages;
}

Magazin::Magazin(const Magazin& other_magazin)
{
	this->Author = other_magazin.Author;
	this->Name = other_magazin.Name;
	this->count_of_page = other_magazin.count_of_page;
}

void Magazin::Show(bool names = false)
{
	if (!names)
	{
		cout << "�����: " << this->Author
			<< "\n��������: " << this->Name
			<< "\n���������� �������: " << this->count_of_page << "\n\n";
	}
	else
	{
		cout << "��������: " << this->Name << "\n\n";
	}
}

void Magazin::Input()
{
	cout << "\n������� ������\n";
	cout << "�����: ";
	cin.seekg(cin.eof());
	getline(cin, this->Author);
	cout << "��������: ";
	cin.seekg(cin.eof());
	getline(cin, this->Name);
	cout << "���������� �������: "; cin >> this->count_of_page;
}

Magazin& Magazin::operator=(const Magazin& other_magazin)
{
	if (this == &other_magazin)
	{
		return *this;
	}
	Print::operator=(other_magazin);
	this->count_of_page = other_magazin.count_of_page;
	return *this;
}