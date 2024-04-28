#include <iostream>
#include <chrono> //директива для нахождения времени выполнения части кода
using namespace std;


double rek(int n, double x) //рекурсивная функция
{
	if (!n) return 0;
	return rek(n - 1, x) + (cos(2 * n * x) / (4 * pow(n,2) - 1));
}

double ne_rek(int n, double x) //функция для прямого вычисления значения
{
	double s = 0;
	for (int i = 1; i <= n; i++) s += cos(2 * i * x) / (4 * pow(i, 2) - 1);
	return s;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	int n;
	double x;
	cout << "Введите количество членов ряда N: ";
	cin >> n;
	while (n < 0)
	{
		cout << "Введите N > 0: ";
		cin >> n;
	}
	cout << "Введите относительно какого x нужно найти сумму: ";
	cin >> x;
	auto start_rek = chrono::high_resolution_clock::now(); //время, в которое рекурсивная функция начала свою работу
	cout << "Результат через рекурсивную функцию: " << rek(n, x);
	auto end_rek = chrono::high_resolution_clock::now(); //время, в которое рекурсивная функция закончила свою работу
	chrono::duration<float> time_rek = end_rek - start_rek; //находим разницу между этим временем
	cout << ", время: " << time_rek.count() << " сек." << endl;
	auto start_ne_rek = chrono::high_resolution_clock::now(); //начало для не рекурсивной функции
	cout << "Результат через прямое вычисление значения функции: " << ne_rek(n, x);
	auto end_ne_rek = chrono::high_resolution_clock::now(); //конец для не рекурсивной функции
	chrono::duration<float> time_ne_rek = end_ne_rek - start_ne_rek; //разница
	cout << ", время: " << time_ne_rek.count() << " сек." << endl;
	return 0;
}