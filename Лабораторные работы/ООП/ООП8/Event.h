#pragma once

const int EvNothing = 0;
const int EvMessage = 100;
const int CmCreateGroup = 1; //m создать группу
const int CmAddToGroup = 2; //+ добавить в группу элемент
const int CmRemoveFromGroup = 3; //- удалить элемент из группы
const int CmShow = 4; //s Вывести информацию об элементах группы
const int CmShowName = 5; //z Вывести информацию о названиях всех элементов группы 
const int CmResize = 6; //r Изменить размер группы
const int CmExit = 7; //q Конец работы

struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int settings;
		};
	};
};