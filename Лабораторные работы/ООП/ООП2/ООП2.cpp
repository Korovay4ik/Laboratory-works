#include <iostream>
#include <string>
using namespace std;

#include "salary.h"

Salary make_salary()
{
	string name; double casing; int bonus;
	cout << "Введите имя: ";
	cin.seekg(cin.eof());
	getline(cin, name);
	cout << "Введите оклад: ";
	cin >> casing;
	cout << "Введите премию в %: ";
	cin >> bonus;
	Salary salary(name, casing, bonus);
	return salary;
}

int main()
{
	system("chcp 1251>null");
	Salary man1;
	man1.print();
	Salary man2("Ктото Ктотович Ктотович", 100, 10);
	man2.print();
	Salary man3;
	man3.setName("Этот Этович Этович");
	man3.setSalary(200);
	man3.setBonus(20);
	cout << "ФИО: " << man3.getName() << "\nОклад: " << man3.getSalary() << "\nБонус: " << man3.getBonus() << "%\n\n";
	Salary man4 = make_salary();
	man4.print();
	return 0;
}

Salary::Salary()
{
	cout << "Конструктор без параметров для объекта " << this << endl;
	name = "никто";
	casing = 0;
	bonus = 0;
}

Salary::Salary(string name, double casing, int bonus)
{
	cout << "Конструктор с параметрами для объекта " << this << endl;
	this->name = name;
	this->casing = casing;
	this->bonus = bonus;
}

Salary::Salary(const Salary& other)
{
	cout << "Конструктор копирования для объекта " << this << endl;
	this->name = other.name;
	this->casing = other.casing;
	this->bonus = other.bonus;
}

Salary::~Salary()
{
	cout << "Вызов деструктора для объекта " << this << endl;
}

void Salary::setName(string name)
{
	this->name = name;
}

void Salary::setSalary(double casing)
{
	this->casing = casing;
}

void Salary::setBonus(int bonus)
{
	this->bonus = bonus;
}

string Salary::getName()
{
	return this->name;
}

double Salary::getSalary()
{
	return this->casing;
}

int Salary::getBonus()
{
	return this->bonus;
}

void Salary::print()
{
	cout << "ФИО: " << this->name << "\nОклад: " << this->casing << "\nПремия: " << this->bonus << "%\n\n";
}