#pragma once

void randomize(Pair& pair)
{
	int x = rand() % 1001;
	double y = (rand() % 100001) * 0.01;
	pair = Pair(x, y);
}

bool write_to_a_file(int N) 
{
	fstream F1("ООП10.txt", ios::out | ios::trunc);
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
	if (!F1) 
	{
		cout << "Ошибка открытия файла\n";
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
	fstream F1("ООП10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "Ошибка открытия файла\n";
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
	fstream F1("ООП10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "Ошибка открытия файла\n";
		return 0;
	}
	fstream tmp_file("temporary_file.txt", ios::out | ios::trunc);
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
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
	remove("ООП10.txt");
	rename("temporary_file.txt", "ООП10.txt");
	return 1;
}

template<typename T>
bool add_L(T L) 
{
	fstream F1("ООП10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "Ошибка открытия файла\n";
		return 0;
	}
	fstream tmp_file("temporary_file.txt", ios::out | ios::trunc);
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
	Pair pair;
	while (F1 >> pair)
	{
		pair = pair + L;
		tmp_file << pair << "\n";
	}
	F1.close();
	tmp_file.close();
	remove("ООП10.txt");
	rename("temporary_file.txt", "ООП10.txt");
	return 1;
}

bool add_k_el_after(int number, int quantity) 
{
	fstream F1("ООП10.txt", ios::in);
	//in чтение
	if (!F1) 
	{
		cout << "Ошибка открытия файла\n";
		return 0;
	}
	fstream tmp_file("temporary_file.txt", ios::out | ios::trunc);
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
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
		cout << "Достигнут конец файла! Элемент с номером " << number << "не найден\n";
	}
	F1.close();
	tmp_file.close();
	remove("ООП10.txt");
	rename("temporary_file.txt", "ООП10.txt");
	return 1;
}

int choosing_an_action() 
{
	cout << "Выберите действие\n";
	cout << "1 - Вывести содержимое файла\n";
	cout << "2 - Перезаписать содержимое файла\n";
	cout << "3 - Удалить все записи меньшие заданного значения\n";
	cout << "4 - Увеличить все записи с заданным значением на число L\n";
	cout << "5 - Добавить K записей после элемента с заданным номером\n";
	cout << "0 - Конец работы\n";
	int choice;
	do 
	{
		cout << ">  ";
		cin >> choice;
	} while (choice < 0 || choice > 5);
	cout << "\n";
	return choice;
}