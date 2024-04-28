#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include "Pair.h"
#include <random>
using namespace std;

class Greater_Than_Pair
{
public:
    bool operator()(Pair& p1, Pair& p2)
    {
        return p1 < p2;
    }
};

void randomize(Pair&);
void generate_Q(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>&, int);
ostream& operator<<(ostream&, priority_queue<Pair, vector<Pair>, Greater_Than_Pair>);
Pair all_sum(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>);
void remove_from_range(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>&, Pair&, Pair&);
Pair maximum_pair(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>&);
Pair minimum_pair(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>);
priority_queue<Pair, vector<Pair>, Greater_Than_Pair> add_to_all(priority_queue<Pair,
    vector<Pair>, Greater_Than_Pair>&, Pair&);
bool find_para(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>, int&, Pair&);

int main() 
{
    system("chcp 1251 > Null");
    srand(time(0));
    int N;
    do 
    {
        cout << "Введите размер очереди: ";
        cin >> N;
    } while (N < 1);

    priority_queue<Pair, vector<Pair>, Greater_Than_Pair> qst;
    generate_Q(qst, N);
    cout << qst;

    Pair sum = all_sum(qst);
    sum.setFirst(sum.getFirst() / qst.size());
    sum.setSecond(sum.getSecond() / qst.size());
    cout << "\nСреднее арифметическое: " << sum << "\n\n";
    qst.push(sum);
    cout << "После добавления среднего арифметического:\n" << qst << "\n";

    Pair first_el, second_el;
    cout << "Введите две пары чисел, из диапазона которых будут удалены пары списка\n";
    cout << "Первая пара\n"; cin >> first_el;
    cout << "Вторая пара\n"; cin >> second_el;

    if (first_el > second_el) 
    {
        swap(first_el, second_el);
    }
    remove_from_range(qst, first_el, second_el);
    cout << "\nПосле удаления из диапазона:\n" << qst << "\n";

    Pair max_el = maximum_pair(qst);
    Pair min_el = minimum_pair(qst);
    cout << "Минимальный элемент: " << min_el << "\n";
    cout << "Максимальный элемент: " << max_el << "\n\n";

    sum = max_el + min_el;
    cout << "Сумма максимального и минимального элементов: " << sum << "\n";
    qst = add_to_all(qst, sum);
    cout << "После добавления суммы максимального и минимального к каждой паре чисел:\n" << qst;

    cout << "Введите значение first, по которому необходимо найти пару: ";
    int tmp_first;
    cin >> tmp_first;
    Pair finded_element;
    bool flag = find_para(qst, tmp_first, finded_element);
    if (flag) 
    {
        cout << "Элемент найден: " << finded_element << "\n";
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

void generate_Q(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>& my_Q, int Q_size)
{
    Pair tmp(0, 0);
    for (int i = 0; i < Q_size; i++)
    {
        randomize(tmp);
        my_Q.push(tmp);
    }
}

ostream& operator<<(ostream& stream, priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q)
{
    while (!my_Q.empty())
    {
        Pair user = my_Q.top();
        cout << user << endl;
        my_Q.pop();
    }
    return stream;
}

Pair all_sum(priority_queue<Pair, vector<Pair>, Greater_Than_Pair> temp_Q)
{
    Pair sum(0, 0);
    while (!temp_Q.empty())
    {
        Pair top_pair = temp_Q.top();
        sum = sum + top_pair;
        temp_Q.pop();
    }
    return sum;
}

void remove_from_range(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>& my_Q, Pair& range_1, Pair& range_2)
{
    priority_queue<Pair, vector<Pair>, Greater_Than_Pair> queue_1;
    while (!my_Q.empty())
    {
        Pair top_pair = my_Q.top();
        if (!(top_pair > range_1 && top_pair < range_2))
        {
            queue_1.push(top_pair);
        }
        my_Q.pop();
    }
    my_Q = queue_1;
}

Pair maximum_pair(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>& my_Q)
{
    return my_Q.top();
}

Pair minimum_pair(priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q)
{
    Pair min_p;
    while (!my_Q.empty())
    {
        min_p = my_Q.top();
        my_Q.pop();
    }
    return min_p;
}

priority_queue<Pair, vector<Pair>, Greater_Than_Pair> add_to_all(priority_queue<Pair,
    vector<Pair>, Greater_Than_Pair>& my_Q, Pair& pair)
{
    priority_queue<Pair, vector<Pair>, Greater_Than_Pair> queue_1;
    Pair top_pair = my_Q.top();
    while (!my_Q.empty())
    {
        top_pair = my_Q.top();
        queue_1.push(top_pair + pair);
        my_Q.pop();
    }
    return queue_1;
}

bool find_para(priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q, int& x, Pair& finded_element)
{
    bool flag = false;
    while (!my_Q.empty() && !flag)
    {
        finded_element = my_Q.top();
        if (x == finded_element.getFirst())
        {
            flag = true;
        }
        my_Q.pop();
    }
    return flag;
}