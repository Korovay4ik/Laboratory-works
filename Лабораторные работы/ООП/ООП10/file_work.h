#pragma once

void randomize(Pair& pair)
{
	int x = rand() % 1001;
	double y = (rand() % 100001) * 0.01;
	pair = Pair(x, y);
}

bool write_to_a_file(int N) 
{
	fstream F1("���10.txt", ios::out | ios::trunc);
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 
	if (!F1) 
	{
		cout << "������ �������� �����\n";
		return 0;
	}
	for (int i = 0; i < N; i++) 
	{
		Pair pair;
		randomize(pair);
		F1 << pair << "\n";
	}
	F1.close();
	return 1;
}

bool print_file() 
{
	fstream F1("���10.txt", ios::in);
	//in ������
	if (!F1) 
	{
		cout << "������ �������� �����\n";
		return 0;
	}
	Pair pair;
	while (F1 >> pair)
	{
		cout << pair << "\n";
	}
	return 1;
}

bool removing_el_smaller_than(Pair& para) 
{
	fstream F1("���10.txt", ios::in);
	//in ������
	if (!F1) 
	{
		cout << "������ �������� �����\n";
		return 0;
	}
	fstream tmp_file("temporary_file.txt", ios::out | ios::trunc);
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 
	Pair pair;
	while (F1 >> pair)
	{
		if (pair > para)
		{
			tmp_file << pair << "\n";
		}
	}
	F1.close();
	tmp_file.close();
	remove("���10.txt");
	rename("temporary_file.txt", "���10.txt");
	return 1;
}

template<typename T>
bool add_L(T L) 
{
	fstream F1("���10.txt", ios::in);
	//in ������
	if (!F1) 
	{
		cout << "������ �������� �����\n";
		return 0;
	}
	fstream tmp_file("temporary_file.txt", ios::out | ios::trunc);
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 
	Pair pair;
	while (F1 >> pair)
	{
		pair = pair + L;
		tmp_file << pair << "\n";
	}
	F1.close();
	tmp_file.close();
	remove("���10.txt");
	rename("temporary_file.txt", "���10.txt");
	return 1;
}

bool add_k_el_after(int number, int quantity) 
{
	fstream F1("���10.txt", ios::in);
	//in ������
	if (!F1) 
	{
		cout << "������ �������� �����\n";
		return 0;
	}
	fstream tmp_file("temporary_file.txt", ios::out | ios::trunc);
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 
	Pair pair;
	int counter = 0;
	while (F1 >> pair)
	{
		counter++;
		tmp_file << pair << "\n";

		if (counter == number) 
		{
			for (int i = 0; i < quantity; i++) 
			{
				Pair new_pair;
				randomize(new_pair);
				tmp_file << new_pair << "\n";
			}
		}
	}
	if (counter < number)
	{
		cout << "��������� ����� �����! ������� � ������� " << number << "�� ������\n";
	}
	F1.close();
	tmp_file.close();
	remove("���10.txt");
	rename("temporary_file.txt", "���10.txt");
	return 1;
}

int choosing_an_action() 
{
	cout << "�������� ��������\n";
	cout << "1 - ������� ���������� �����\n";
	cout << "2 - ������������ ���������� �����\n";
	cout << "3 - ������� ��� ������ ������� ��������� ��������\n";
	cout << "4 - ��������� ��� ������ � �������� ��������� �� ����� L\n";
	cout << "5 - �������� K ������� ����� �������� � �������� �������\n";
	cout << "0 - ����� ������\n";
	int choice;
	do 
	{
		cout << ">  ";
		cin >> choice;
	} while (choice < 0 || choice > 5);
	cout << "\n";
	return choice;
}