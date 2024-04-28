#pragma once
#include <iostream>
#include "iterator.h"

struct Node
{
	int data;
	Node* ptr_to_next_node = nullptr;
};

class List
{
private:
	int size;
	Node* head_node;
	Node* tail_node;
	Iterator begin_iterator;
	Iterator end_iterator;
public:
	List(int);
	List(const List&);
	~List();
	void push_back(int);
	Iterator first_element();
	Iterator last_element();
	void pop_front();
	int operator () ();
	int& operator[](int);
	List& operator = (const List&);
	List operator *(List&);
	friend std::ostream& operator << (std::ostream&, const List&);
	friend std::istream& operator >> (std::istream&, List&);
};