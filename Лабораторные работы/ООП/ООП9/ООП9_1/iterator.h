#pragma once
#include "list.h"

class Iterator
{
private:
	friend struct Node;
	friend class List;
	Node* element;
public:
	Iterator();
	Iterator(const Iterator&);
	~Iterator() {}
	bool operator != (const Iterator&);
	Iterator& operator ++(int);
	Iterator& operator +(const int);
	int& operator *();
};