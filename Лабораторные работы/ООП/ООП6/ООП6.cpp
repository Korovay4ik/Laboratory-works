#include <iostream>
using namespace std;

#include "list.h"
#include "iterator.h"

void list_rand(List& list);
void print_iterator(List& list);

int main() 
{
    system("chcp 1251 > Null");
    srand(time(0));
    List list_1(10);
    cout << "list_1\n";
    cout << list_1 << "\n\n";

    list_rand(list_1);
    cout << "list_1: " << list_1 << "\n\n";
    cout << "Первый элемент: " << *(list_1.first_element()) << "\n";
    cout << "Последний элемент: " << *(list_1.last_element()) << "\n\n";

    List list_2(list_1);
    cout << "list_2\n";
    cout << list_2 << "\n\n";

    List list_3(5);
    cout << "list_3: ";
    cin >> list_3;
    cout << list_3 << "\n";
    cout << "Первый элемент: " << *(list_3.first_element()) << "\n";
    cout << "Последний элемент: " << *(list_3.last_element()) << "\n\n";

    List list_4 = list_2 * list_3;
    cout << "list_4\n";
    cout << list_4 << "\n\n";

    cout << "Вывод элементов list_1 с помощью Iterator\n";
    print_iterator(list_1);
    cout << endl;
    return 0;
}

void list_rand(List& list) 
{
    for (int i = 0; i < list(); i++) 
    {
        list[i] = rand() % (100 + 1) - 50;
    }
}

void print_iterator(List& list) 
{
    for (Iterator iter = list.first_element(); iter != list.last_element() + 1; iter++) 
    {
        cout << *iter << ' ';
    }
}