#pragma once
#include "Print.h"

class Magazin : public Print
{
protected:
	int count_of_page;
public:
	Magazin();
	Magazin(string, string, int);
	Magazin(const Magazin&);
	~Magazin() {}
	void Show(bool) override;
	void Input() override;
	Magazin& operator = (const Magazin&);

	void setPages(int& pages) { this->count_of_page = pages; }
	int getPages() { return this->count_of_page; }
};