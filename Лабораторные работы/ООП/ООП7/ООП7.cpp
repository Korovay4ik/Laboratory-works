#include <iostream>
using namespace std;
#include "List.h"
#include "Pair.h"

int main() 
{
    system("chcp 1251>null");
    List<int> list1(5);
    List<float> list2(5);
    List<double> list3(5);
    List<Pair> list4(3);
    List<int> list5(5);

    cout << "list1 int\n";
    cin >> list1;
    cout << list1;
    cout << "\nВывод элемента под номером 1: ";
    cout << list1[0] << "\n";

    cout << "\nlist2 float\n";
    cin >> list2;
    cout << list2;
    cout << "\nВывод элемента под номером 3: ";
    cout << list2[2] << "\n";

    cout << "\nlist3 double\n";
    cin >> list3;
    cout << list3 << "\n";
    
    cout << "\nlist4 Pair\n";
    cin >> list4;
    cout << list4;
    cout << "\nВывод элемента под номером 2: \n";
    cout << list4[1] << "\n";
    list4[1] + 100;
    list4[1] + 99.3;
    cout << list4 << "\n";

    cout << "\nlist5 = list1\n";
    list5 = list1;
    cout << list5 << "\n";

    cout << "\nlist1 * list5\n" << list1 * list5;
    return 0;
}