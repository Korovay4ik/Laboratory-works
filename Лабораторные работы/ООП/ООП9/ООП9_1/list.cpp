#pragma once
#include "list.h"
#include "iterator.h"

List::List(int size)
{
	const int Max_size = 30;
	if (size < 0) throw 3;
	if (size > Max_size) throw 4;
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			this->push_back(0);
		}
	}
	else
	{
		this->head_node = nullptr;
		this->tail_node = nullptr;
	}
	this->begin_iterator.element = this->head_node;
	this->end_iterator.element = this->tail_node;
}

List::List(const List& list)
{
	this->size = 0;
	Node* current_node = list.head_node;
	while (current_node != nullptr)
	{
		push_back(current_node->data);
		current_node = current_node->ptr_to_next_node;
	}
	this->begin_iterator.element = this->head_node;
	this->end_iterator.element = this->tail_node;
}

List::~List()
{
	while (head_node != nullptr)
	{
		this->pop_front();
	}
}

void List::push_back(int data)
{
	Node* New_Node = new Node;
	New_Node->data = data;
	if (this->head_node == nullptr)
	{
		this->head_node = New_Node;
		this->tail_node = New_Node;
		this->begin_iterator.element = this->head_node;
		this->end_iterator.element = this->tail_node;
	}
	else
	{
		this->tail_node->ptr_to_next_node = New_Node;
		this->tail_node = New_Node;
		this->end_iterator.element = this->tail_node;
	}
	this->size++;
}

Iterator List::first_element()
{
	return this->begin_iterator;
}

Iterator List::last_element()
{
	return this->end_iterator;
}

void List::pop_front()
{
	int temp;
	if (this->tail_node != nullptr)
	{
		Node* current_node = this->head_node;
		head_node = current_node->ptr_to_next_node;
		temp = current_node->data;
		this->size--;
		this->begin_iterator.element = head_node;
	}
}

int List::operator () ()
{
	return this->size;
}

int& List::operator[](int index)
{
	if (index < 0) throw 1;
	if (index > size - 1) throw 2;
	Node* current_node = this->head_node;
	for (int i = 0; i != index; i++)
	{
		current_node = current_node->ptr_to_next_node;
	}
	return current_node->data;
}

List& List::operator = (const List& list)
{
	if (this != &list)
	{
		while (head_node != nullptr)
		{
			this->pop_front();
		}
		size = 0;
		Node* current_node = list.head_node;
		while (current_node != nullptr)
		{
			push_back(current_node->data);
			current_node = current_node->ptr_to_next_node;
		}
	}
	return *this;
}

List List::operator *(List& list)
{
	int temp_size;
	if (this->size > list.size)
	{
		temp_size = list.size;
	}
	else
	{
		temp_size = this->size;
	}
	List temp_list(temp_size);
	for (int i = 0; i < temp_size; i++)
	{
		temp_list[i] = (*this)[i] * list[i];
	}
	return temp_list;
}

std::ostream& operator <<(std::ostream& stream, const List& list)
{
	std::cout << "Вывод элементов списка: \n";
	Node* current_node = list.head_node;
	while (current_node != nullptr)
	{
		stream << current_node->data << ' ';
		current_node = current_node->ptr_to_next_node;
	}
	return stream;
}

std::istream& operator >>(std::istream& stream, List& list)
{
	std::cout << "Введите элементы списка: ";
	Node* current_node = list.head_node;
	while (current_node != nullptr)
	{
		stream >> current_node->data;
		current_node = current_node->ptr_to_next_node;
	}
	return stream;
}