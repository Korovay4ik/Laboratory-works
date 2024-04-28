#include <iostream>
using namespace std;
#include "list.h"
#include "iterator.h"

void list_rand(List& list);
void print_iterator(List& list);
void msg_error(int& x) 
{
    cout << "Ошибка с кодом " << x << "\n";
    switch (x) 
    {
    case 1:
        cout << "Недопустимый индекс списка! Отрицательный индекс недопустим.\n";
        break;
    case 2:
        cout << "Недопустимый индекс списка! Индекс больше текущего размера списка.\n";
        break;
    case 3:
        cout << "Недопустимый размер списка! Отрицательный рамер недопустим.\n";
        break;
    case 4:
        cout << "Недопустимый размер списка! Превышен максимальный размер.\n";
        break;
    default:
        break;
    }
    cout << "\n";
}

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

    try
    {
        int size;
        cout << "Размер list_3: "; cin >> size;
        List list_3(size);
        cout << "list_3\n";
        cin >> list_3;
        cout << list_3 << "\n\n";

        int index;
        cout << "Элемент с каким индексом вывести: "; cin >> index;
        cout << "Элемент: " << list_3[index] << "\n\n";

        List list_4(15);
        list_rand(list_4);
        cout << "list_4\n";
        cout << list_4 << "\n\n";

        List list_5 = list_3 * list_4;
        cout << "list_5 = list_3 * list_4\n";
        cout << list_5 << "\n\n";
    }
    catch (int& x)
    {
        msg_error(x);
    }
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
