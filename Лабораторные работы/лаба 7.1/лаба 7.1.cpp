#include <iostream>

using namespace std;

void func(int n, int* a);

void func(int* a, int n, int m);

int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(0));
	int n, m;
	cout << "Введите размерность массива (n, m), если массив одномерный, то m = 0: ";
	cin >> n >> m;
	if (!m)
	{
		cout << "Введите одномерный массив: " << endl;
		int a[100];
		for (int i = 0; i < n; i++) cin >> a[i];
		func(n, a);
	}
	else
	{
		int a[100][100];
		int* ptr = &a[0][0];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = rand() % 100;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		func(ptr, n, m);
	}
	return 0;
}

void func(int n, int* a)
{
	int zero_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) zero_count++;
	}
	if (zero_count < 2) cout << "В массиве меньше двух нулевых элементов.";
	else
	{
		bool flag = false;
		int i_1, i_2;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 0)
			{
				if (!flag)
				{
					i_1 = i;
					flag = true;
				}
				else i_2 = i;
			}
		}
		while (i_1 + 1 != i_2)
		{
			for (int i = i_2; i < n; i++) a[i - 1] = a[i];
			n--;
			i_2--;
		}
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	}
}

void func(int* a, int n, int m)
{
	for (int k = 1; k < n; k++)
	{
		for (int i = k; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				*(a + 100 * i + j) = *(a + 100 * (i + 1) + j);
			}
		}
		n--;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << *(a + 100 * i + j) << ' ';
		}
		cout << endl;
	}
}