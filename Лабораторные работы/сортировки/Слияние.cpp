#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#define lenght_mas 25

using namespace std;

template <typename T>
void print_mas(T mas)
{
	cout << mas[0];
	for (int i = 1; i < lenght_mas; i++)
		cout << ' ' << mas[i];
	cout << '\n';
}
void Merge(int* mas, int startIndex, int endIndex)
{
	vector<int> temp;
	int start_first_part = startIndex;
	int end_first_part = (startIndex + endIndex) / 2;
	int start_second_part = end_first_part;

	while (int(temp.size()) < endIndex - startIndex)
	{
		if (start_first_part >= end_first_part
			|| (start_second_part < endIndex
				&& mas[start_second_part] <= mas[start_first_part]))
		{
			temp.push_back(mas[start_second_part]);
			start_second_part++;
		}
		else
		{
			temp.push_back(mas[start_first_part]);
			start_first_part++;
		}
	}
	for (int i = startIndex; i < endIndex; ++i)
		mas[i] = temp[i - startIndex];
}
void MergeSort(int* mas, int startIndex, int endIndex)
{
	if ((endIndex - startIndex) < 2)
	{
		return;
	}
	if ((endIndex - startIndex) == 2)
	{
		if (mas[startIndex] > mas[startIndex + 1])
		{
			swap(mas[startIndex], mas[startIndex + 1]);
			return;
		}
	}
	MergeSort(mas, startIndex, (startIndex + endIndex) / 2);
	MergeSort(mas, (startIndex + endIndex) / 2, endIndex);
	Merge(mas, startIndex, endIndex);
}
void CountingSort(int* mas)
{
	int max_element = mas[0];
	int min_element = mas[0];
	for (int i = 0; i < int(lenght_mas); i++)
	{
		if (max_element < mas[i]) max_element = mas[i];
		else if (min_element > mas[i]) min_element = mas[i];
	}
	vector<int> temp(max_element - min_element + 1);
	for (int i = 0; i < int(lenght_mas); i++)
	{
		temp[mas[i] - min_element]++;
	}
	int index = 0;
	for (int i = 0; i < max_element - min_element + 1; i++)
	{
		for (int step = 0; step < temp[i]; step++)
		{
			mas[index] = i + min_element;
			index++;
		}
	}
}
void BucketSort(int* mas) {

	int max_element = mas[0];
	int min_element = mas[0]; 
	for (int i = 1; i < lenght_mas; i++) 
	{
		if (mas[i] > max_element) 
		{
			max_element = mas[i];
		}
		else if (mas[i] < min_element) 
		{
			min_element = mas[i];
		}
	}
	int count_buckets = ((max_element - min_element) / 10);
	int** buckets = new int* [count_buckets];
	for (int i = 0; i < count_buckets; i++) 
	{
		buckets[i] = new int[lenght_mas];
	}
	for (int i = 0; i < lenght_mas; i++) 
	{
		int bucket_index = ((mas[i] - min_element) / count_buckets);
		buckets[bucket_index][i] = mas[i];
	}

	for (int i = 0; i < count_buckets; i++) 
	{
		cout << i + 1 << "-й блок: ";
		for (int j = 0; j < lenght_mas; j++)
		{
			if (buckets[i][j] > -1)
				cout << buckets[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < count_buckets; i++)
	{
		for (int j = 0; j < lenght_mas; j++) 
		{
			for (int k = j + 1; k < lenght_mas; k++) 
			{
				if (buckets[i][j] > buckets[i][k])
				{
					swap(buckets[i][j], buckets[i][k]);
				}
			}
		}
	}
	int counter = 0;
	for (int i = 0; i < count_buckets; i++) 
	{
		for (int j = 0; j < lenght_mas; j++) 
		{
			if (buckets[i][j] > -100) {
				mas[counter++] = buckets[i][j];
			}
		}
	}
	for (int i = 0; i < count_buckets; i++) 
	{
		delete[] buckets[i];
	}
	delete[] buckets;
}
void FastSort(int* mas, int size)
{
	int i = 0;
	int j = size - 1;
	int pivot = mas[size / 2];
	do
	{
		while (mas[i] < pivot)
		{
			i++;
		}
		while (mas[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			swap(mas[i], mas[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		FastSort(mas, j + 1);
	}
	if (i < size)
	{
		FastSort(&mas[i], size - i);
	}
}
void ShellSort(int* mas)
{
	int j, tmp;
	bool flag;
	for (int step = 5; step > 0; step /= 2)
	{
		flag = true;
		for (int i = step; i < lenght_mas; i++)
		{
			tmp = mas[i];
			for (j = i; j >= step && flag; j -= step)
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
}
void KhoarSort(int* mas, int left, int right)
{
	int i, j, pivot;
	i = left;
	j = right;
	pivot = mas[(left + right) / 2];
	do
	{
		while ((mas[i] < pivot) && (i < right))
		{
			i++;
		}
		while ((pivot < mas[j]) && (j > left))
		{
			j--;
		}
		if (i <= j)
		{
			swap(mas[i], mas[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
	{
		KhoarSort(mas, left, j);
	}
	if (i < right)
	{
		KhoarSort(mas, i, right);
	}
}
void natural_merge(vector<int>& vect1, vector<int>& vect2)
{
	for (int i = 0; i < vect2.size(); i++)
	{
		vect1.push_back(vect2[i]);
		for (int j = vect1.size() - 1; j > 0; j--)
		{
			if (vect1[j] < vect1[j - 1])
			{
				swap(vect1[j], vect1[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}
void natural_merge_sort(int* mas)
{	
	vector <vector<int>> series;
	vector<int> new_series;
	for (int i = 0; i <= lenght_mas - 1; i++)
	{
		if (i == lenght_mas - 1)
		{
			new_series.push_back(mas[i]);
			series.push_back(new_series);
			new_series.clear();
		}
		else
		{
			new_series.push_back(mas[i]);
			if (mas[i] > mas[i + 1])
			{
				series.push_back(new_series);
				new_series.clear();
			}
		}
	}
	while (series.size() != 1)
	{
		natural_merge(series[0], series[series.size() - 1]);
		series.pop_back();
	}
	for (int i = 0; i < lenght_mas; i++)
	{
		mas[i] = series[0][i];
	}
}
pair<int, int> ideal_series(pair<int, int> last_count_series, int count_all_series)
{
	int current_num = last_count_series.first + last_count_series.second;
	if (count_all_series > current_num)
	{
		ideal_series({ last_count_series.second, current_num }, count_all_series);
	}
	else
	{
		return last_count_series;
	}
}
void series_merge(vector <vector<int>>& series_1, vector <vector<int>>& series_2, vector <vector<int>>& series_3)
{
	if (series_1.size() == 1 && series_2.size() == 0 && series_3.size() == 0)
	{
		return;
	}
	else if (series_2.size() == 1 && series_1.size() == 0 && series_3.size() == 0)
	{
		return;
	}
	else if (series_3.size() == 1 && series_1.size() == 0 && series_2.size() == 0)
	{
		return;
	}
	int i = series_1.size()-1;
	int j = series_2.size()-1;
	while (j != -1) //пока series_2 не пуста
	{
		natural_merge(series_1[i], series_2[j]);
		series_3.push_back(series_1[i]);
		series_1.pop_back();
		series_2.pop_back();
		i--;
		j--;
	}
	series_merge(series_3, series_1, series_2); //1-ый, там, где больше серий, 2-ой, там где меньше серий (потом пустой), 3-ий, куда сливаются
}
void multiphase_merge_sort(int* mas)
{
	pair <int, int> ideal_pair;
	vector <int> new_series;
	vector <vector<int>> series, series_1, series_2, series_3;
	for (int i = 0; i <= lenght_mas - 1; i++)
	{
		if (i == lenght_mas - 1)
		{
			new_series.push_back(mas[i]);
			series.push_back(new_series);
			new_series.clear();
		}
		else
		{
			new_series.push_back(mas[i]);
			if (mas[i] > mas[i + 1])
			{
				series.push_back(new_series);
				new_series.clear();
			}
		}
	}
	ideal_pair = ideal_series({ 0, 1 }, series.size());
	for (int i = 0; i < ideal_pair.second; i++)
	{
		series_1.push_back(series[i]);
	}
	for (int i = 0; i < ideal_pair.first; i++)
	{
		if (series_1.size() + i + 1 > series.size())
		{
			series_2.push_back({});
		}
		else
		{
			series_2.push_back(series[series_1.size() + i]);
		}
	}
	series_merge(series_1, series_2, series_3);
	for (int i = 0; i < lenght_mas; i++)
	{
		mas[i] = series_1[0][i];
	}
}

int main()
{
	system("chcp 1251>NULL");
	int mas_merge[] = { 178, 14, -15, 0, 23, 56, -74, 32, -4, 5, 3, 20, 89, 100, -35, 65, 75, -18, 65, 1, -6, 32, 1, -15, 5 };
	int mas_counting[] = { -1, 0, 5, -1, 6, 3, 0, 5, 10, -3, 6, -1, 3, 5, 10, -3, 0, 5, -1, 7, 2, 0, 3, 1, 0 };
	int mas_buckets[] = { 21, 32, 1, 7, 56, 43, 26, 110, 54, 4, 36, 38, 9, 97, 3, 101, 98, 15, 94, 0, 29, 12, 84, 100, 2 };
	int mas_fast[] = { 178, 14, -15, -5, 23, -56, -74, -32, -4, 5, 3, 20, 0, -100, -35, -65, 75, -18, 65, 1, -6, 32, 1, -15, 5 };
	int mas_shell[] = { 178, 14, -15, 0, 23, 56, -74, 32, -4, 31, 3, 20, 89, 100, -35, 65, 75, -18, 65, 7, -6, 32, 1, -15, 5 };
	int mas_khoar[] = { 178, 14, -15, -5, 23, -56, -74, -32, -4, 31, 3, 20, 0, -100, -35, -65, 75, -18, 65, 1, -6, 32, 7, -15, 5 };
	int mas_natural_merge[] = { 178, 14, -15, -5, 23, -56, 100, -32, -4, 31, 3, 20, 0, -100, -35, -65, 75, -18, 65, 1, -6, 32, 7, -15, 5 };
	int mas_multiphase_merge[] = { 178, 14, -15, -5, 23, -56, 100, -32, -4, 31, 3, 20, 0, -100, -35, -65, 75, -18, 65, 1, -6, 32, 7, -15, 5 };

	vector <function <void(int)>> functions = { bind(MergeSort, mas_merge, 0, lenght_mas), bind(CountingSort, mas_counting),
		bind(BucketSort, mas_buckets), bind(FastSort, mas_fast, lenght_mas), bind(ShellSort, mas_shell),
		bind(KhoarSort, mas_khoar, 0, lenght_mas - 1), bind(natural_merge_sort, mas_natural_merge), 
		bind(multiphase_merge_sort, mas_multiphase_merge)};
	int* mas_mas[] = { mas_merge, mas_counting, mas_buckets, mas_fast, mas_shell, mas_khoar, mas_natural_merge, mas_multiphase_merge };
	string names_sorts[] = { "\tСортировка слиянием\n", "\tСортировка посчетом\n", "\tБлочная сортировка\n", 
		"\tБыстрая сортировка\n", "\tСортировка Шелла\n", "\tСортировка Хоара\n", "\tСортировка естественным слиянием\n", 
		"\tСортировка двухфазным слиянием\n" };
	int k = 0;
	for (const auto& fn : functions)
	{
		cout << names_sorts[k];
		cout << "Исходный массив: ";
		print_mas(mas_mas[k]);
		auto start_sort = chrono::high_resolution_clock::now();
		fn(k);
		auto end_sort = chrono::high_resolution_clock::now();
		chrono::duration<float> time_sort = end_sort - start_sort;
		cout << "Отсортированный массив: ";
		print_mas(mas_mas[k]);
		cout << "Время сортировки: " << time_sort.count() << " сек\n\n";
		k++;
	}
}