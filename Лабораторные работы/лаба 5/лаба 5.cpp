#include <iostream>
using namespace std;


int main() 
{
	int a[100][100], n, max, max_i, max_j;
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	cout << "Двумерный массив NxN, введите N: ";
	cin >> n;
	for (int i = 0; i < n; i++) //задается двумерный массив из слчайных чисел
	{
		for (int j = 0; j < n; j++) a[i][j] = rand() % 90 + 10;
	}
	cout << "Массив:\n";
	for (int i = 0; i < n; i++) //вывод массива
	{
		for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
		cout << endl;
	}
	for (int k = n-1; k >= 0; k--) // цикл по элементам побочной диагонали
	{
		max = a[n-k-1][k]; //максимальный элемент = элементу, лежащему на главной диагонали
		max_i = n - k - 1;
		max_j = k;
		for (int i = n-k-1; i < n; i++) //цикл по строкам подмассива, с правым верхним элементом на побочной диагонали
		{
			for (int j = k; j >= 0; j--) //цикл по столбцам подмассива, с правым верхним элементом на побочной диагонали
			{
				if (a[i][j] > max) //находим максимум в подмассиве
				{
					max = a[i][j];
					max_i = i;
					max_j = j;
				}
			}
		}
		for (int j = 0; j < n; j++) //меняем местами нужные строки
		{
			swap(a[n - k - 1][j], a[max_i][j]);
		}
		for (int i = 0; i < n; i++) //меняем местами нужные столбцы
		{
			swap(a[i][k], a[i][max_j]);
		}
	}
	cout << "Получившийся массив:" << endl;
	for (int i = 0; i < n; i++) //вывод массива
	{
		for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
		cout << endl;
	}
}