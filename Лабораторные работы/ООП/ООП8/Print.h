#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Object.h"

class Print : public Object
{
protected:
	string Author;
	string Name;
public:
	Print();
	Print(string, string);
	Print(const Print&);
	virtual ~Print() {}
	void Show(bool) override;
	void Input() override;
	Print& operator=(const Print&);
	void setAuthor(string& author) { this->Author = author; }
	void setName(string& name) { this->Name = name; }
	string getAuthor() { return this->Author; }
	string getName() { return this->Name; }
};