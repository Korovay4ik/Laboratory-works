#pragma once

const int EvNothing = 0;
const int EvMessage = 100;
const int CmCreateGroup = 1; //m ������� ������
const int CmAddToGroup = 2; //+ �������� � ������ �������
const int CmRemoveFromGroup = 3; //- ������� ������� �� ������
const int CmShow = 4; //s ������� ���������� �� ��������� ������
const int CmShowName = 5; //z ������� ���������� � ��������� ���� ��������� ������ 
const int CmResize = 6; //r �������� ������ ������
const int CmExit = 7; //q ����� ������

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