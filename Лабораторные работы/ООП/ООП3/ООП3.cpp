#include <iostream>
using namespace std;

#include "Pair.h"

int main()
{
	system("chcp 1251>null");
	Pair pair1(3, 4.3);
	pair1.Print();

	Pair pair2(pair1);
	pair2.Print();
	pair2 + 3;
	pair2.Print();
	pair2 + 3.3;
	pair2.Print();
	pair2 - pair1;
	pair2.Print();

	Pair pair3;
	cout << pair3 << endl;
	pair3 = pair2;
	cout << pair3 << endl;

	Pair pair4;
	cout << "Введите пару:\n";
	cin >> pair4;
	cout << pair4 << endl;
	return 0;
}