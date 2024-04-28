#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	string str;
	cout << "Введите строку: "; getline(cin, str); str += ' ';
	char mas_num[] = { '1', '2', '3','4','5','6','7','8','9','0' };
	char mas_abc[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t',
	'u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
	'T','U','V','W','X','Y','Z', '_', '$' }; //54
	int i_0 = 0, i = 0;
	bool flag = true;
	while (str[i] != '\0')
	{
		for (int j = 0; j < 54 && flag; j++)
		{
			if (str[i] == mas_abc[j] || str[i] == 32) flag = false;
		}
		for (int j = 0; j < 10 && flag; j++)
		{
			if (str[i] == mas_num[j] && i_0 != i) flag = false;
		}
		if (flag)
		{
			while (str[i_0] != ' ') str.erase(i_0, 1);
			str.erase(i_0, 1);
			i = i_0;
		}
		else i++;
		if (str[i] == ' ') i_0 = i + 1;
		flag = true;
	}
	cout << str;
	return 0;
}