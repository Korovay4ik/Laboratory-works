#pragma once

class Salary
{
private:
	string name;
	double casing;
	int bonus;
public:
	Salary();
	Salary(string, double, int);
	Salary(const Salary&);
	~Salary();
	void setName(string);
	void setSalary(double);
	void setBonus(int);
	string getName();
	double getSalary();
	int getBonus();
	void print();
};