#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int hashTable_size;
extern int& M = hashTable_size;

#include "Hash.h"
#include "Generators.h"


struct Human
{
    string nameSP = "-";
    string birthday = "-";
    string pas_num = "-";
};

struct Hash_Table
{
    vector<Human> table;
    int collision_cnt = 0;

    void print()
    {
        cout << "Таблица: \n";
        int position = 1;
        for (int i = 0; i < int(table.size()); i++)
        {
            if (table[i].nameSP == "-")
                continue;
            cout << position << ")" << " ФИО: " << table[i].nameSP;
            cout << " | Дата рождения: " << table[i].birthday;
            cout << " | Номер паспорта: " << table[i].pas_num << endl;
            position++;
        }
        if (position == 1)
        {
            cout << "Таблица пуста\n";
        }
    }
    void collision_solve(int index, Human new_element)
    {
        collision_cnt++;
        int cnt = 0;
        while (table[index].nameSP != "-" && cnt < M)
        {
            index++;
            if (index == M)
            {
                index = 0;
            }
            cnt++;
        }
        if (cnt == M)
            cout << "\nОшибка устранения коллизии\n";
        else
            table[index] = new_element;
    }
    int find_element(string& element)
    {
        int index = getHash(element);
        int cnt = 0;
        while (table[index].birthday != element && cnt <= M)
        {
            index++;
            if (index == M)
            {
                index = 0;
            }
            cnt++;
        }
        if (cnt >= M)
        {
            return -1;
        }
        else
        {
            return index;
        }
    }
    void add_element()
    {
        Human temp_human;
        cout << "Введите ФИО: ";
        cin.seekg(cin.eof());
        getline(cin, temp_human.nameSP);
        cout << "Введите дату рождения: ";
        cin.seekg(cin.eof());
        getline(cin, temp_human.birthday);
        cout << "Введите номер паспорта: ";
        cin.seekg(cin.eof());
        getline(cin, temp_human.pas_num);
        int index = getHash(temp_human.birthday);
        if (table[index].nameSP != "-")
        {
            collision_solve(index, temp_human);
        }
        else
        {
            table[index] = temp_human;
        }
    }
    void remove_element(string& element)
    {
        int index = find_element(element);
        if (index == -1)
        {
            cout << "Не удалось найти элемент\n";
        }
        else
        {
            table[index].nameSP = "-";
            table[index].pas_num = "-";
            table[index].birthday = "-";
            cout << "\nЭлемент успешно удален\n";
        }
    }
    void remove_element(int& index)
    {
        table[index].nameSP = "-";
        table[index].pas_num = "-";
        table[index].birthday = "-";
    }
    void delete_table()
    {
        for (int i = 0; i < hashTable_size; i++)
        {
            remove_element(i);
        }
        cout << "\nУдаление таблицы...\n\n";
    }
    void file_print(string file)
    {
        ofstream out (file);
        out << "Таблица: \n";
        int position = 1;
        for (int i = 0; i < int(table.size()); i++)
        {
            if (table[i].nameSP == "-")
                continue;
            out << position << ")" << " ФИО: " << table[i].nameSP;
            out << " | Дата рождения: " << table[i].birthday;
            out << " | Номер паспорта: " << table[i].pas_num << endl;
            position++;
        }
        out.close();
    }
    void recovery_table(string file)
    {
        cout << "\nВосстановление таблицы...\n\n";
        ifstream in(file);
        Human temp_human;
        string str;
        getline(in, str);
        while (getline(in, str))
        {
            int index_1 = 0, index_2;
            for (index_1; index_1 < str.length(); index_1++)
            {
                if (str[index_1] == ':')
                {
                    index_2 = index_1;
                }
                if (str[index_1] == '|')
                {
                    break;
                }
            }
            temp_human.nameSP = str.substr(index_2 + 2, index_1 - 3 - index_2);
            temp_human.birthday = str.substr(index_1 + 17, 10);
            temp_human.pas_num = str.substr(index_1 + 46, 6);
            int index = getHash(temp_human.birthday);
            if (table[index].nameSP != "-")
            {
                collision_solve(index, temp_human);
            }
            else
            {
                table[index] = temp_human;
            }
        }
        in.close();
        file_print("F2.txt");
    }
};

int main()
{
    system("chcp 1251>null");
    srand(time(0));
    cout << "Кол-во человек: ";
    cin >> hashTable_size;
    Hash_Table people;
    people.table.resize(hashTable_size);
    for (int i = 0; i < hashTable_size; i++)
    {
        Human temp_human;
        temp_human.nameSP = generate_fullName();
        temp_human.birthday = generate_date();
        temp_human.pas_num = generate_pasNum();
        int index = getHash(temp_human.nameSP);
        if (people.table[index].nameSP != "-")
        {
            people.collision_solve(index, temp_human);
        }
        else
        {
            people.table[index] = temp_human;
        }
    }

    cout << "Количество колллизий: " << people.collision_cnt << endl;
    people.print();
    cout << "Введите ключ для удаления [Дата рождения]: ";
    string temp_string;
    cin.seekg(cin.eof());
    getline(cin, temp_string);
    people.remove_element(temp_string);
    people.print();
    cout << "\tДобавление элемента:\n";
    people.add_element();
    people.print();
    cout << "Введите ключ для поиска [Дата рождения]: ";
    cin.seekg(cin.eof());
    getline(cin, temp_string);
    int index = people.find_element(temp_string);
    if (index == -1)
    {
        cout << "Не удалось найти элемент\n";
    }
    else
    {
        cout << "\nЭлемент найден, его номер: " << index+1 << endl;
    }
    people.file_print("F1.txt");
    people.delete_table();
    people.print();
    people.recovery_table("F1.txt");
    people.print();
}