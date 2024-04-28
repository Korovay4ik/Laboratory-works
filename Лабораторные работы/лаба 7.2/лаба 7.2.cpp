#include <iostream>

using namespace std;

double lenght(int m, ...);
double square(int m, ...);
double square1(int m, ...);

int main()
{
	setlocale(0, "Ru");
	cout << "S = " << square1(10, 1, 1, 3, 5, 5, 3, 4, 1, 2, 0);
}

double lenght(int m, ...)
{
	int* ptr = &m;
	int x = ptr[2] - ptr[6], y = ptr[4] - ptr[8];
	return pow(x * x + y * y, 0.5);
}

double square(int m, ...)
{
	int* ptr = &m;
	double a, b, c, p;
	a = lenght(4, ptr[2], ptr[4], ptr[6], ptr[8]);
	b = lenght(4, ptr[6], ptr[8], ptr[10], ptr[12]);
	c = lenght(4, ptr[2], ptr[4], ptr[10], ptr[12]);
	p = (a + b + c) / 2;
	return pow(p * (p - a) * (p - b) * (p - c), 0.5);
}

double square1(int m, ...)
{
	int* ptr = &m;
	int x1, x2, y1, y2;
	double max = -1, c;
	for (int i = 1; i < m; i += 2)
	{
		for (int j = i; j < m-4; j+=2)
		{
			if (j * 2 + 8 > m * 2) c = lenght(4, ptr[i * 2], ptr[i * 2 + 2], ptr[(j * 2 + 8) - (m * 2)], ptr[(j * 2 + 10) - (m * 2)]);
			else c = lenght(4, ptr[i * 2], ptr[i * 2 + 2], ptr[j * 2 + 8], ptr[j * 2 + 10]);
			if (c > max)
			{
				max = c;
				if (i * 2 + 8 > m * 2)
				{
					x1 = ptr[i * 2]; x2 = ptr[(j * 2 + 8) - (m * 2)]; y1 = ptr[i * 2 + 2]; y2 = ptr[(j * 2 + 10) - (m * 2)];
				}
				else
				{
					x1 = ptr[i * 2]; x2 = ptr[j * 2 + 8]; y1 = ptr[i * 2 + 2]; y2 = ptr[j * 2 + 10];
				}
			}
		}
	}
	return square(6, 0, 0, x1, y1, x2, y2);
}