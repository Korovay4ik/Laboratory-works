#pragma once

string correct_date(int n)
{
    string date = to_string(n);
    if (date.size() < 2)
    {
        date = '0' + date;
    }
    return date;
}

string generate_date()
{
    return correct_date(rand() % 30 + 1) + "." + correct_date(rand() % 12 + 1) + "." + to_string(2024 - (rand() % 90));
}

string generate_pasNum()
{
    return to_string(rand()%900000*10 + 100000 + rand()%10);
}

string generate_fullName()
{
    string surnames[] = { "Иванов", "Карпов", "Козлов", "Орлов", "Жданов", "Волков", "Попкин", "Петров", "Андреев", "Лебедев", "Макаров" };
    string names[] = { "Александр", "Сергей", "Андрей", "Семен", "Денис", "Максим" };
    string patronymics[] = { "Александрович", "Игоревич", "Павлович", "Юрьевич", "Сергеевич", "Романович", "Тимофеевич" };
    return surnames[rand() % 11] + " " + names[rand() % 6] + " " + patronymics[rand() % 7];
}