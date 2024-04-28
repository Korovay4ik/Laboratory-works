#include <iostream>
#include <fstream>
using namespace std;

#include "Pair.h"
#include "file_work.h"

int main() 
{
	system("chcp 1251 > Null");
	srand(time(0));
	int N;
	do
	{
		cout << "Введите кол-во элементов: ";
		cin >> N;
	} while (N < 1);
	cout << "\n";
	write_to_a_file(N);
	bool flag = true;
	while (flag) 
	{
		int current_action = choosing_an_action();
		int tmp_1;
		double tmp_2;
		Pair pair;
		switch (current_action) 
		{
		case 1:
			cout << "Текущее содержимое файла:\n";
			print_file();
			cout << "\n";
			break;
		case 2:
			do 
			{
				cout << "Введите кол-во элементов: ";
				cin >> tmp_1;
			} while (tmp_1 < 1);
			write_to_a_file(tmp_1);
			break;
		case 3:
			cout << "Введите элемент, (все элементы со значением меньше введенного будут удалены)\n";
			cin >> pair;
			removing_el_smaller_than(pair);
			break;
		case 4:
			do 
			{
				cout << "Какое число вы хотите ввести?\n"
				     << "1 - целое \n2 - вещественное\n";
				cin >> N;
			} while (N < 1 || N>2);
			switch (N) 
			{
			case 1:
				cout << "Введите ЦЕЛОЕ число: ";
				cin >> tmp_1;
				add_L(tmp_1);
				break;
			default:
				cout << "Введите ВЕЩЕСТВЕННОЕ число: ";
				cin >> tmp_2;
				add_L(tmp_2);
				break;
			}
			break;
		case 5:
			do 
			{
				cout << "Введите НОМЕР, после которого необходимо добавить k элементов\n";
				cin >> N;
			} while (N < 1);
			do 
			{
				cout << "Введите количество элементов, которое необходимо добавить\n";
				cin >> tmp_1;
			} while (tmp_1 < 1);
			add_k_el_after(N, tmp_1);
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}