#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

int main()
{
	system("chcp 1251>null");
    Person person1("Ктото Ктотович Ктотович", 5);
    cout << person1;
    Person person2;
    cout << person2;
    Person person3(person1);
    cout << person3;

    Student student1("Ктототамов Ктототам", 5, "math", 2);
    cout << student1 << endl;
    student1.mark_status();

    Student student2;
    cout << student2 << endl << endl;
    cin >> student2;
    cout << student2 << endl;
    student2.mark_status();

    Student student3(student1);
    cout << student3 << endl;
    student3.mark_status();
	return 0;
}