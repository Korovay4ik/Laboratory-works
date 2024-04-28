#include <iostream>
using namespace std;


void vivod_massiva(int* a, int n) //функция, которая просто выводит массив
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void vivod_ot_k(int* a, int n) //функция, котрая выводит массив от k-го элемента до k-1-го элемента
{
	int k;
	cout << "Введите k: ";
	cin >> k;
	while (k > n || k < 1) //проверка на дурака
	{
		cout << "Введите другое k: ";
		cin >> k;
	}
	cout << "Вывод массива от k до k-1: ";
	for (int i = k - 1; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	for (int i = 0; i < k - 1; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int a[100], n;
	cout << "Введите кол-во элементов в массиве: ";
	cin >> n;
	for (int i = 0; i < n; i++) //задаем массив
	{
		a[i] = rand() % 100;
	}
	cout << "Массив: ";
	vivod_massiva(a, n);
	vivod_ot_k(a, n);
	a[n] = a[0]; //добавляем первый элемент
	a[n + 1] = a[n - 1]; //добавляем последний элемент
	n += 2;
	cout << "Добавляем первый и последний элемент: ";
	vivod_massiva(a, n);
	for (int i = 1; i < n; i++) //удаляются четные элементы
	{
		for (int j = i; j < n; j++) //сдвигает элементы на 1 влево, начиная с i-го
		{
			a[j] = a[j + 1];
		}
		n -= 1;
	}
	cout << "Удаляем все четные элементы: ";
	vivod_massiva(a, n);
	vivod_ot_k(a, n);
	return 0;
}