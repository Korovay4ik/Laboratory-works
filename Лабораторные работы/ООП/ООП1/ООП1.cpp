#include <iostream>
#include "Progression.h"
using namespace std;

int main()
{
	system("chcp 1251>null");
	cout << "Введите a0 и r: ";
	double first;
	int second, index;
	cin >> first >> second;
	Progression progressia(first, second);
	do
	{
		cout << "Для какого j-го элемента вывести значение функции: ";
		cin >> index;
	} while (index < 0);
	cout << "Значение функции = " << progressia.element(index) << '\n';
	return 0;
}

Progression::Progression(double first, int second)
{
	this->first = first;
	this->second = second;
}

double Progression::element(int j)
{
	return first * pow(second, j);
}