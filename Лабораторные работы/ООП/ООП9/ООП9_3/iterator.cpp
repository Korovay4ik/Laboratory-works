#pragma once
#include "list.h"
#include "iterator.h"

Iterator::Iterator()
{
	this->element = nullptr;
}

Iterator::Iterator(const Iterator& iterator)
{
	this->element = iterator.element;
}

bool Iterator::operator!=(const Iterator& iterator)
{
	return this->element != iterator.element;
}

Iterator& Iterator::operator++(int)
{
	this->element = this->element->ptr_to_next_node;
	return *this;
}

Iterator& Iterator::operator+(const int number)
{
	for (int i = 0; i < number; i++)
	{
		if (this->element->ptr_to_next_node == nullptr) throw ErrorIndexIsTooBig();
		this->element = this->element->ptr_to_next_node;
	}
	return *this;
}

int& Iterator::operator*()
{
	return this->element->data;
}