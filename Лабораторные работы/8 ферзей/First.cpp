#include "First.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

static int chess[8][8];
bool start = false;

void unferz(int i, int j);
void ferz(int i, int j);
bool rek(int i);

[assembly:System::Diagnostics::DebuggableAttribute(true, true)] ;
[STAThreadAttribute]

int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Ferz::First form;
	Application::Run(%form);
}

inline System::Void Ferz::First::exit_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i(0); i < 64; i++)
	{
		delete Pictures[i];
	}
	delete Pictures;
	this->Close();
}

inline System::Void Ferz::First::but_start_Click(System::Object^ sender, System::EventArgs^ e) {
	Delay();
	for (int i(0); i < 8; i++) for (int j(0); j < 8; j++) chess[i][j] = 0;
	rek(0);
}

System::Void Ferz::First::print()
{
	Sleep(Ferz::First::delay);
	for (int i(0); i < 8; i++)
	{
		for (int j(0); j < 8; j++)
		{
			Pictures[i * 8 + j]->Refresh();
			if (chess[i][j] == 0)
				Pictures[i * 8 + j]->Image = Image::FromFile("resources\\void.png");
			else if ((chess[i][j] == 9))
				Pictures[i*8+j]->Image = Image::FromFile("resources\\Q.png");
			else if ((chess[i][j] > 0 && chess[i][j] < 8))
				Pictures[i * 8 + j]->Image = Image::FromFile("resources\\X.png");
		}
	}
	return System::Void();
}

void unferz(int i, int j)
{
	for (int k(0); k < 8; k++)
	{
		chess[k][j] -= 1;
		chess[i][k] -= 1;
		int h = i - j + k;
		if (h >= 0 && h < 8) chess[h][k] -= 1;
		h = i + j - k;
		if (h >= 0 && h < 8) chess[k][h] -= 1;
	}
	chess[i][j] = 0;
}

void ferz(int i, int j)
{
	for (int k(0); k < 8; k++)
	{
		chess[k][j] += 1;
		chess[i][k] += 1;
		int h = i - j + k;
		if (h >= 0 && h < 8) chess[h][k] += 1;
		h = i + j - k;
		if (h >= 0 && h < 8) chess[k][h] += 1;
	}
	chess[i][j] = 9;
}

bool rek(int i)
{
	bool setferz = false;
	for (int j = 0; j < 8; j++)
	{
		if (!chess[i][j])
		{
			ferz(i, j);
			Ferz::First::print();
			if (i == 7)
			{
				DialogResult result = MessageBox::Show("Найти следующее решение?",
					"Найдено решение!", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (result == ::DialogResult::Yes)
				{
					unferz(i, j);
					return false;
				}
				else
					setferz = true;
			}
			else
			{
				setferz = rek(i + 1);
				if (!setferz)
				{
					unferz(i, j);
					Ferz::First::print();
				}
			}
		}
	}
	return setferz;
}
