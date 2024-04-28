#pragma once
#include "Dialog.h"

Dialog::Dialog() : Vector()
{
	this->EndState = 0;
}

void Dialog::GetEvent(TEvent&event)
{
	cout << "Выберите действие\n"
		<<"m: Создать группу (Пример команды: m10)\n"
		<< "+: Добавить элемент в группу\n"
		<< "-: Удалить элемент из группы\n"
		<< "s: Вывести информацию об элементах группы\n"
		<< "z: Вывести информацию о названиях всех элементов группы\n"
		<< "r: Изменить размер группы (Пример команды: r7)\n"
		<< "q: Конец работы\n";
	cout << "> ";
	string str, set; cin >> str;
	char code = str[0];
	if (is_command(code))
	{
		event.what = EvMessage;
		switch (code)
		{
		case 'm':
			event.command = CmCreateGroup;
			break;
		case '+':
			event.command = CmAddToGroup;
			break;
		case '-':
			event.command = CmRemoveFromGroup;
			break;
		case 's':
			event.command = CmShow;
			break;
		case 'z':
			event.command = CmShowName;
			break;
		case 'r':
			event.command = CmResize;
			break;
		case 'q':
			event.command = CmExit;
			break;
		}
		if (str.size() > 1)
		{
			set = str.substr(1, str.size() - 1);
			int settings = atoi(set.c_str());
			event.settings = settings;
		}
	}
	else
	{
		event.what = EvNothing;
	}
}

bool Dialog::is_command(char action)
{
	int i = 0;
	string str = "m+-szrq";
	while (i < str.size())
	{
		if (action == str[i])
		{
			return true;
		}
		i++;
	}
	return false;
}

int Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);
		cout << "\n";
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == EvNothing)
	{
		cout << "Такой команды нет\n\n";
	}
	else
	{
		switch (event.command)
		{
		case CmCreateGroup:
			create(event.settings);
			ClearEvent(event);
			break;
		case CmAddToGroup:
			Add();
			ClearEvent(event);
			break;
		case CmRemoveFromGroup:
			Del();
			ClearEvent(event);
			break;
		case CmShow:
			print(false);
			ClearEvent(event);
			break;
		case CmShowName:
			print(true);
			ClearEvent(event);
			break;
		case CmResize:
			resize(event.settings);
			ClearEvent(event);
			break;
		case CmExit:
			EndExec();
			ClearEvent(event);
			break;
		default:
			break;
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = EvNothing;
}

int Dialog::Valid()
{
	if (EndState == 0)
	{
		return 0;
	}
	return 1;
}

void Dialog::EndExec()
{
	EndState = 1;
}