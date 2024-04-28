#include <iostream>
#include <string>
using namespace std;

#include "Person.h"
#include "VECTOR.h"

int main()
{
	system("chcp 1251>null");
	Person person1 ("faokfaf", 12);
	cout << person1;
	person1.Show();

	Student student1("Вася", 34, "инфа", 3);
	cout << student1;
	student1.Show();

	Vector vector(5);
	Person person2("Максим", 19);
	cin >> person2;
	Student student2;
	cin >> student2;
	Object* ptr = &person2;
	vector.Add(ptr);
	ptr = &student2;
	vector.Add(ptr);
	cout << endl;
	cout << vector;
	return 0;
}