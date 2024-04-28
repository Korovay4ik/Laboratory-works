#include <iostream>
#include <functional>
#include <algorithm>
#include "Pair.h"
#include <map>
using namespace std;

void randomize(Pair&);
void generate_M(map<Pair, Pair>&, int);
ostream& operator<<(ostream&, const pair<Pair, Pair>);
ostream& operator<<(ostream&, const map<Pair, Pair>&);
bool isInRange(Pair&, Pair&, Pair&);
void remove_from_range(map<Pair, Pair>&, Pair&, Pair&);
Pair minimum_pair(map<Pair, Pair>&);
Pair maximum_pair(map<Pair, Pair>&);
void all_sum(map<Pair, Pair>&, Pair&, Pair&);
map<Pair, Pair> add_to_all(map<Pair, Pair>&, Pair&, Pair&);
bool findPair(map<Pair, Pair>&, Pair&, Pair&);

int main() 
{
    system("chcp 1251 > Null");
    srand(time(0));
    int N;
    do {
        cout << "Введите размер словаря: ";
        cin >> N;
    } while (N < 1);
    Pair sum_1(0, 0), sum_2(0, 0), sum_key(0, 0), sum_value(0, 0);
    map<Pair, Pair> mapp;
    generate_M(mapp, N);
    cout << "Сгенерированный словарь:\n" << mapp << "\n";

    all_sum(mapp, sum_1, sum_2);
    sum_1 / mapp.size();
    sum_2 / mapp.size();
    cout << "Среднее арифметическое ключей " << sum_1 << "\n";
    cout << "Среднее арифметическое значений " << sum_2 << "\n\n";
    mapp[sum_1] = sum_2;
    cout << "После добавления среднего арифметического:\n" << mapp << "\n";

    Pair first_el, second_el;
    cout << "Введите две пары чисел (ключей), из диапазона которых будут удалены пары словаря\n";
    cout << "Первая пара:\n";
    cin >> first_el;
    cout << "Вторая пара:\n";
    cin >> second_el;
    if (first_el > second_el) 
    {
        swap(first_el, second_el);
    }
    remove_from_range(mapp, first_el, second_el);
    cout << "\nПосле удаления из диапазона\n" << mapp << "\n";

    Pair max_el = maximum_pair(mapp);
    Pair min_el = minimum_pair(mapp);
    findPair(mapp, min_el, sum_1);
    findPair(mapp, max_el, sum_2);
    cout << "Минимальный элемент по ключу: " << min_el << "\n";
    cout << "Ключ - " << min_el << " Значение - " << sum_1 << "\n";
    cout << "Максимальный элемент по ключу: " << max_el << "\n";
    cout << "Ключ - " << max_el << " Значение - " << sum_2 << "\n\n";

    sum_key = min_el + max_el;
    sum_value = sum_1 + sum_2;
    cout << "Сумма максимального и минимального элементов:\n";
    cout << "Ключ - " << sum_key << " Значение - " << sum_value << "\n\n";
    mapp = add_to_all(mapp, sum_key, sum_value);
    cout << "После добавления суммы максимального и минимального к каждой паре чисел:\n";
    cout << mapp << "\n";

    cout << "Введите ключевое значение, по которому необходимо найти пару\n";
    cin >> first_el;
    bool found = findPair(mapp, first_el, second_el);
    cout << "\n";
    if (found) 
    {
        cout << "Элемент найден.\n";
        cout << "Ключ - " << first_el << " Значение - " << second_el << "\n";
    }
    else 
    {
        cout << "Элемент не найден =(\n";
    }
    return 0;
}

void randomize(Pair& p)
{
    int x = rand() % 1001;
    double y = (rand() % 100001) * 0.01;
    p = Pair(x, y);
}

void generate_M(map<Pair, Pair>& my_M, int M_size)
{
    Pair qwe_1(0, 0), qwe_2(0, 0);
    for (int i = 0; i < M_size; i++)
    {
        randomize(qwe_1);
        randomize(qwe_2);
        my_M[qwe_1] = qwe_2;
    }
}

ostream& operator<<(ostream& stream, const pair<Pair, Pair> p)
{
    stream << "Ключ - " << p.first << "\tЗначение - " << p.second << "\n";
    return stream;
}

ostream& operator<<(ostream& stream, const map<Pair, Pair>& my_M)
{
    map<Pair, Pair>::const_iterator Iter = my_M.begin();
    while (Iter != my_M.end())
    {
        cout << *Iter++;
    }
    return stream;
}

bool isInRange(Pair& key, Pair& lower, Pair& upper)
{
    return key > lower && key < upper;
}

void remove_from_range(map<Pair, Pair>& my_M, Pair& range_1, Pair& range_2)
{
    auto iterator = my_M.begin();
    Pair key;
    while (iterator != my_M.end())
    {
        key = iterator->first;
        if (!isInRange(key, range_1, range_2))
        {
            ++iterator;
        }
        else
        {
            iterator = my_M.erase(iterator);
        }
    }
}

Pair minimum_pair(map<Pair, Pair>& my_M)
{
    return my_M.begin()->first;
}

Pair maximum_pair(map<Pair, Pair>& my_M)
{
    auto iter = my_M.begin();
    Pair tmp_pair;
    while (iter != my_M.end())
    {
        tmp_pair = iter->first;
        ++iter;
    }
    return tmp_pair;
}

void all_sum(map<Pair, Pair>& my_M, Pair& key, Pair& value)
{
    for (const auto& pair : my_M)
    {
        Pair tmp = pair.first;
        key = key + tmp;
        tmp = pair.second;
        value = value + tmp;
    }
}

map<Pair, Pair> add_to_all(map<Pair, Pair>& my_M, Pair& key, Pair& value)
{
    map<Pair, Pair> tmp_map;
    for (const auto& pair : my_M)
    {
        Pair tmp_key = pair.first;
        Pair tmp_value = pair.second;
        tmp_map[tmp_key + key] = (tmp_value + value);
    }
    return tmp_map;
}

bool findPair(map<Pair, Pair>& my_M, Pair& key, Pair& value)
{
    auto iter = my_M.find(key);
    if (iter != my_M.end())
    {
        value = Pair(iter->second);
        return true;
    }
    else
    {
        return false;
    }
}