#include <iostream>
#include <chrono>
#include <string>
#include <functional>
#include <vector>

using namespace std;

int Line_search(int* mas, int& key)
{
	int cnt = 0, index = -1;
	for (int i = 0; i < _msize(mas) / sizeof(mas[0]) && index == -1; i++)
	{
		if (mas[i] == key)
		{
			index = i;
		}
	}
	return index;
}
void ShellSort(int* mas)
{
	int j, tmp, step;
	int lenght_mas = _msize(mas) / sizeof(mas[0]);
	for (int i = 2; i < lenght_mas/2; i++)
	{
		if (lenght_mas % i == 0)
		{
			step = i;
		}
	}
	for (step; step > 0; step /= 2)
	{
		for (int i = step; i < lenght_mas; i++)
		{
			tmp = mas[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mas[j - step])
				{
					mas[j] = mas[j - step];
				}
				else
				{
					break;
				}
			}
			mas[j] = tmp;
		}
	}
	cout << "\n";
	for (int i = 0; i < lenght_mas; i++)
	{
		cout << mas[i] << ' ';
	}
	cout << "\n";
}
int binary_search(int* mas, int& key)
{
	int lenght_mas = _msize(mas) / sizeof(mas[0]);
	int left = 0, right = lenght_mas - 1, mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (mas[mid] == key)
		{
			return mid;
		}
		else
		{
			if (mas[mid] < key)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
}
int interpol_search(int* mas, int& key)
{
	
	int lenght_mas = _msize(mas) / sizeof(mas[0]);
	int left = 0, right = lenght_mas - 1, mid, index = -1;
	while (left <= right && index == -1)
	{
		mid = left + (((key - mas[left]) * (right - left)) / (mas[right] - mas[left]));
		if (mas[mid] == key)
		{
			index = mid;
		}
		else
		{
			if (mas[mid] < key)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return index;
}
int line_str_search(string& str, string& substr)
{
	bool found_str;
	for (int i = 0; i <= str.length() - substr.length(); i++)
	{
		found_str = true;
		if (str[i] == substr[0])
		{
			for (int j = 1; j < substr.length() && found_str; j++)
			{
				found_str = (str[i + j] == substr[j]);
			}
			if (found_str)
			{
				return i;
			}
		}
	}
	return -1;
}	
void table_formation(int* shift_table, string& substr)
{
	for (int i = 0; i < 256; i++)
	{
		shift_table[i] = substr.length();
	}
	for (int i = substr.length() - 2; i >= 0; i--)
	{
		if (shift_table[int((unsigned char)substr[i])] == substr.length()) 
		{
			shift_table[int((unsigned char)substr[i])] = substr.length() - i - 1;
		}
	}
}
int Boiere_Moore(string& str, string& substr)
{
	int shift_table[256];
	table_formation(shift_table, substr);
	int index_element = -1;
	int current_last_char = substr.length() - 1;
	while (current_last_char < str.length() && index_element == -1)
	{
		bool flag = true;
		for (int i = substr.length() - 1; i >= 0 && index_element == -1 && flag; i--)
		{
			if (substr[i] != str[current_last_char - substr.length() + i + 1])
			{
				current_last_char += shift_table[int((unsigned char)str[current_last_char - substr.length() + i + 1])];
				flag = false;
			}
			else if (i == 0)
			{
				index_element = current_last_char - substr.length() + 1;
			}
		}
	}
	return index_element;
}
void prefix_function(string& substr, int* mas_prefix)
{
	int i = 1, j = 0;
	while (i < substr.length())
	{
		if (substr[i] == substr[j])
		{
			mas_prefix[i] = j++;
			i++;
		}
		else
		{
			if (!j)
			{
				mas_prefix[i] = 0;
				i++;
			}
			else
			{
				j = mas_prefix[j - 1];
			}
		}
	}
}
int KMP(string& str, string& substr)
{
	int* mas_prefix = new int[substr.length()];
	mas_prefix[0] = 0;
	int str_index = 0, substr_index = 0, index_element = -1;
	prefix_function(substr, mas_prefix);

	while (str_index < str.length() && index_element == -1)
	{
		if (substr[substr_index] == str[str_index])
		{
			str_index++;
			substr_index++;
		}
		if (substr_index == substr.length())
		{
			index_element = str_index - substr.length();
		}
		else if (str_index < str.length() && substr[substr_index] != str[str_index])
		{
			if (!substr_index)
			{
				str_index++;
			}
			else
			{
				substr_index = mas_prefix[substr_index - 1];
			}
		}
	}
	delete[] mas_prefix;
	return index_element;
}

int main()
{
	system("chcp 1251>NULL");
	srand(time(0));
	cout << "Длинна массива: ";
	int lenght_mas, key = 11;
	cin >> lenght_mas;
	int* mas = new int[lenght_mas];
	for (int i = 0; i < lenght_mas; i++)
	{
		mas[i] = rand()%101;
		cout << mas[i] << ' ';
	}
	cout << "\nКакой элемент найти: ";
	cin >> key;
	string str, substr;
	cout << "\nВведите строку: ";
	cin.seekg(cin.eof());
	getline(cin, str);
	cout << "Введите подстроку: ";
	getline(cin, substr);
	
	vector <function<int(int)>> functions = { bind(Line_search, mas, key), bind(binary_search, mas, key),
		bind(interpol_search, mas, key), bind(line_str_search, str, substr), 
		bind(Boiere_Moore, str, substr), bind(KMP, str, substr) };
	string name_search[] = { "\n\tМетод линейного поиска\n", "\n\tМетод бинарного поиска\n", 
		"\n\tМетод интерполяционного поиска\n", "\n\tМетод прямого поиска подстроки в строке\n", 
		"\n\tМетод Бойера-Мура\n", "\n\tМетод Кнута-Морриса-Пратта\n" };
	int k = 0;
	for (const auto& fn : functions)
	{
		cout << name_search[k];
		auto start_search = chrono::high_resolution_clock::now();
		int index = fn(k);
		auto end_search = chrono::high_resolution_clock::now();
		chrono::duration<float> time_search = end_search - start_search;
		if (index == -1)
		{
			if (k < 3)
			{
				cout << "Элемент не найдены\n";
			}
			else
			{
				cout << "Подстрока не найдена\n";
			}
		}
		else
		{
			if (k < 3)
			{
				cout << "Номер элемента: " << index + 1 << '\n';
			} 
			else
			{
				cout << "Номер первого символа подстроки в строке: " << index + 1 << '\n';
			}
		}
		cout << "Время поиска: " << time_search.count() << " сек\n";
		if (!k)
		{
			ShellSort(mas);
		}
		k++;
	}
	delete[]mas;
	return 0;
}