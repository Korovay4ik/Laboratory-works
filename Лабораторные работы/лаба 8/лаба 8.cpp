#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Student
{
	string name, surname, patronymic, date, home;
	int rate;
};

int n;

void info(vector <Student>& a, int i); //для заполнения студентами
void del_student(vector <Student>& a, int i); //удаление студента
bool is_date(Student s1, Student s2); //совпадают ли даты
void insert_stud(vector <Student>& a, string surname); //вставить студента
void print_stud(vector <Student>& a); //вывод в файл

int main()
{
	system("chcp 1251");
	system("cls");
	vector <Student> students;
	do
	{
		cout << "Введите кол-во студентов: "; cin >> n;
	} while (n < 1);
	for (int i = 0; i < n; i++) info(students, i);

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (is_date(students[i], students[j]))
			{
				del_student(students, i);
				del_student(students, j);
				n -= 2;
			}
		}
	}
	string surname;
	cout << "Введите фамилию, перед которой нужно вставить студента: "; cin >> surname;
	insert_stud(students, surname);
	print_stud(students);
	return 0;
}

void info(vector <Student>& a, int i)
{
	string name, surname, patronymic, date, home;
	int rate;
	if (i == -1) cout << "Информация о новом студенте." << endl;
	else cout << "Информация о " << i + 1 << "-ом студенте." << endl;
	cout << "Имя студента: "; cin.seekg(cin.eof()); getline(cin, name);
	cout << "Фамилия студента: "; cin.seekg(cin.eof()); getline(cin, surname);
	cout << "Отчество студента: "; cin.seekg(cin.eof()); getline(cin, patronymic);
	cout << "Дата рождения студента (ДД.ММ.ГГГГ): "; cin.seekg(cin.eof()); getline(cin, date);
	cout << "Адрес студента: "; cin.seekg(cin.eof()); getline(cin, home);
	cout << "Рейтинг студента: "; cin >> rate;
	cout << endl;
	a.push_back(Student{ name, surname, patronymic, date, home, rate });
}

void del_student(vector <Student>& a, int i)
{
	for (int j = i; j < n - 1; j++) a[j] = a[j + 1];
	a.pop_back();
}

bool is_date(Student s1, Student s2)
{
	if (s1.date == s2.date) return 1;
	else return 0;
}

void insert_stud(vector <Student>& a, string surname)
{
	bool flag = false;
	for (int i(0); i < n+1 && !flag; i++)
	{
		if (i == n) cout << "Фамилия не найдена";
		else
		{
			if (a[i].surname == surname)
			{
				info(a, -1);
				n++;
				for (int j = n - 1; j != i; j--)
				{
					Student tmp = a.back();
					a[j] = a[j - 1];
					a[i] = tmp;
				}
				flag = true;
			}
		}
	}
}

void print_stud(vector <Student>& a)
{
	ofstream output("F.txt");
	for (int i = 0; i < n; i++)
	{
		output << "Информация о " << i + 1 << "-ом студенте." << endl;
		output << "Имя студента: " << a[i].name << endl;
		output << "Фамилия студента: " << a[i].surname << endl;
		output << "Отчество студента: " << a[i].patronymic << endl;
		output << "Дата рождения студента (ДД.ММ.ГГГГ): " << a[i].date << endl;
		output << "Адрес студента: " << a[i].home << endl;
		output << "Рейтинг студента: " << a[i].rate << endl << endl;
	}
	output.close();
}