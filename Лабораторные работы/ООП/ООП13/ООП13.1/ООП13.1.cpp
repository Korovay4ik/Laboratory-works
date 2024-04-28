#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
#include "Pair.h"
using namespace std;

ostream& operator<<(ostream&, list<Pair>&);

void randomize(Pair&);

int main() 
{
    system("chcp 1251 > Null");
    srand(time(0));
    int list_size;
    do 
    {
        cout << "Введите размер списка: ";
        cin >> list_size;
    } while (list_size < 1);

    Pair sum;
    list<Pair> list_1(list_size);

    generate(list_1.begin(), list_1.end(), []() {Pair p; randomize(p); return p; });
    cout << "Сгенерированный список:\n" << list_1 << "\n";

    for_each(list_1.begin(), list_1.end(), [&sum](Pair& p) {sum = sum + p; });

    sum.setFirst(sum.getFirst() / list_1.size());
    sum.setSecond(sum.getSecond() / list_1.size());
    cout << "Среднее арифметическое " << sum << "\n\n";

    list_1.push_back(sum);
    cout << "После добавления среднего арифметического:\n" << list_1 << "\n";

    Pair first_el, second_el;

    cout << "Введите две пары чисел, из диапазона которых будут удалены пары списка\n";
    cout << "Первая пара:\n";
    cin >> first_el;
    cout << "Вторая пара:\n";
    cin >> second_el;

    if (first_el > second_el) 
    {
        swap(first_el, second_el);
    }

    list<Pair>::iterator iter = remove_if(list_1.begin(), list_1.end(), 
        [first_el, second_el](Pair& p) {return p > first_el && p < second_el; });
    list_1.erase(iter, list_1.end());
    if (list_1.size() != 0)
    {
        cout << "\nПосле удаления из диапазона\n" << list_1 << "\n";

        pair<list<Pair>::iterator, list<Pair>::iterator> minmax_pair = minmax_element(list_1.begin(), list_1.end());
        cout << "Минимальный элемент: " << *minmax_pair.first << "\n";
        cout << "Максимальный элемент: " << *minmax_pair.second << "\n\n";

        Pair sum_pair(minmax_pair.first->getFirst() + minmax_pair.second->getFirst(),
            minmax_pair.first->getSecond() + minmax_pair.second->getSecond());
        cout << "Сумма максимального и минимального элементов " << sum_pair << "\n";

        for_each(list_1.begin(), list_1.end(), [&sum_pair](Pair& p) {p = p + sum_pair; });
        cout << "После добавления суммы максимального и минимального к каждой паре чисел:\n";
        cout << list_1 << "\n";

        cout << "Сортировка по Возрастанию:\n";
        list_1.sort();
        cout << list_1 << "\n";

        cout << "Сортировка по Убыванию:\n";
        list_1.sort([](Pair& a, Pair& b) {return a > b; });
        cout << list_1 << "\n";

        cout << "Введите значение first, по которому необходимо найти пару: ";
        int temp_first;
        cin >> temp_first;

        auto i = find_if(list_1.begin(), list_1.end(), [&temp_first](Pair& p) {return temp_first == p.getFirst(); });
        if (i != list_1.end())
        {
            cout << "Элемент найден: " << *i << "\n";
        }
        else
        {
            cout << "Элемент не найден =(\n";
        }
    }
    else
    {
        cout << "\nСписок пуст\n";
    }
    return 0;
}

ostream& operator<<(ostream& stream, list<Pair>& l)
{
    for_each(l.begin(), l.end(), [](Pair& p) {cout << p << "\n"; });
    return stream;
}

void randomize(Pair& p)
{
    int x = rand() % 1001;
    double y = (rand() % 100001) * 0.01;
    p = Pair(x, y);
}