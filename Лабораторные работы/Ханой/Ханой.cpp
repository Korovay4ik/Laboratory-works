#include <iostream>
#include <windows.h>

using namespace std;
int count2 = 0;

string shaft1[100], shaft2[100], shaft3[100];
int n;

int count(string str);
void print();
void change(string* from, string* to, int j);
void rec(int col, string* from, string* to, string* buff);

int main()
{
	setlocale(LC_ALL, "Ru");
	int c;
	cout << "Введите кол-во колец: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		shaft2[i] = "0"; shaft3[i] = "0";
	}
	for (int i = 0; i < n; i++)
	{
		string str = "";
		for (int j = 0; j < (n - i - 1); j++) str += " ";
		for (int j = 0; j < (i * 2) + 1; j++) str += "=";
		for (int j = 0; j < (n - i - 1); j++) str += " ";
		shaft1[i] = str;
	}
	shaft1[n] = "1"; shaft2[n] = "2"; shaft3[n] = "3";
	cout << "На каком стержне собрать башню? 2 или 3: "; cin >> c;
	while (c != 2 && c != 3)
	{
		cout << "На этом стержне нельзя собрать башню, введите другой: "; cin >> c;
	}
	print();
	if (c == 2) rec(n, shaft1, shaft2, shaft3);
	else rec(n, shaft1, shaft3, shaft2);
	cout << count2;
	return 0;
}

int count(string str)
{
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '=') count++;
	}
	return count;
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		if (shaft1[i] == "0")
		{
			cout << "| ";
			for (int j = 0; j < ((n - 1) * 2 + 1); j++) cout << " ";
			cout << "  ";
		}
		else cout << "| " << shaft1[i] << "  ";
		if (shaft2[i] == "0")
		{
			for (int j = 0; j < ((n - 1) * 2 + 1); j++) cout << " ";
			cout << "  ";
		}
		else cout << shaft2[i] << "  ";
		if (shaft3[i] == "0")
		{
			for (int j = 0; j < ((n - 1) * 2 + 1); j++) cout << " ";
			cout << "  |" << endl;
		}
		else cout << shaft3[i] << "  |" << endl;
	}
	for (int i = 0; i < 3 * ((n - 1) * 2 + 1) + 9; i++) cout << "-";
	cout << endl;
}

void change(string* from, string* to, int j)
{
	int i = 0;
	string str;
	j--;
	while (from[i] == "0") i++;
	while (to[j] != "0") j--;
	str = from[i];
	from[i] = to[j];
	to[j] = str;
}

void rec(int col, string* from, string* to, string* buff)
{
	if (col != 0)
	{
		rec(col - 1, from, buff, to);
		cout << "rec(" << col << ", " << from[n] << ", " << to[n] << ", " << buff[n] << ")" << endl;
		change(from, to, n);
		cout << "Переносим кольцо со стержня " << from[n] << " на стержень " << to[n] << endl;
		count2++;
		Sleep(1000);
		print();
		rec(col - 1, buff, to, from);
		cout << "rec(" << col << ", " << from[n] << ", " << to[n] << ", " << buff[n] << ") - заблокировано" << endl;
	}
}