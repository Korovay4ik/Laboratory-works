#pragma once
#include "Object.h"

class Person : public Object 
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	Person(const Person&);
	~Person();
	void Show() override;
	void setName(const string);
	void setAge(const int);
	void operator = (const Person&);
	friend ostream& operator<<(ostream&, Person&);
	friend istream& operator>>(istream&, Person&);
};

class Student : public Person
{
protected:
	string subject;
	int mark;
public:
	Student();
	Student(string, int, string, int);
	void setSubject(string);
	void setMark(int);
	void mark_status();
	void Show() override;
	friend ostream& operator <<(ostream&, Student&);
	friend istream& operator >>(istream&, Student&);
};