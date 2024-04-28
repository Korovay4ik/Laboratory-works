#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void print_mas(string* a, int n);

int main()
{
	system("chcp 1251");
	system("cls");
	int n, num;
	string str;
	do
	{
		cout << "Введите кол-во строк: "; cin >> n;
	} while (n < 1);
	string* a = new string[n+1];
	Sleep(200);
	cout << "Введите " << n << " строк" << endl;
	for (int i = 0; i < n; i++) 
	{
		cout << i+1 << "-я строка: ";
		cin.seekg(cin.eof());
		getline(cin, a[i]);
	}
	Sleep(300);
	print_mas(a, n);
	cout << endl;
	do
	{
		cout << "Введите номер, куда нужно вставить строку: "; cin >> num;
	} while (num < 1 || num > n+1);
	num--;
	cout << "Введите саму строку: ";
	n++;
	cin.seekg(cin.eof()); 
	getline(cin, a[n - 1]);
	for (int i = n-1; i > num; i--) swap(a[i], a[i-1]);
	Sleep(300);
	print_mas(a, n);
	delete[]a;
	return 0;
}

void print_mas(string* a, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1) cout << a[i] << ", ";
		else cout << a[i] << '.';
	}
	cout << endl;
}