#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* ptr_to_next_node = nullptr;
};

template <typename T>
class List
{
private:
	int size;
	Node<T>* head_node;
	Node<T>* tail_node;
public:
	List(int);
	List(const List<T>&);
	~List();
	void push_back(T);
	void pop_front();
	int operator () ();
	T& operator[](int);
	List<T>& operator = (const List<T>&);
	List<T> operator *(List<T>&);
	friend std::ostream& operator << (std::ostream& stream, const List<T>& list)
	{
		std::cout << "Вывод элементов: \n";
		Node<T>* current_node = list.head_node;
		while (current_node != nullptr)
		{
			stream << current_node->data << ' ';
			current_node = current_node->ptr_to_next_node;
		}
		return stream;
	}
	friend std::istream& operator >> (std::istream& stream, List<T>& list)
	{
		std::cout << "Введите элементы: ";
		Node<T>* current_node = list.head_node;
		while (current_node != nullptr)
		{
			stream >> current_node->data;
			current_node = current_node->ptr_to_next_node;
		}
		return stream;
	}
};

template <typename T>
List<T>::List(int size)
{
	if (size > 0)
	{
		Node<T>* node = new Node<T>;
		this->head_node = node;
		this->tail_node = node;
		for (int i = 1; i < size; i++)
		{
			Node<T>* New_Node = new Node<T>;
			tail_node->ptr_to_next_node = New_Node;
			tail_node = New_Node;
		}
		this->size = size;
	}
	else
	{
		this->head_node = nullptr;
		this->tail_node = nullptr;
	}
}

template <typename T>
List<T>::List(const List& list)
{
	this->size = 0;
	Node<T>* current_node = list.head_node;
	while (current_node != nullptr)
	{
		push_back(current_node->data);
		current_node = current_node->ptr_to_next_node;
	}
}

template <typename T>
List<T>::~List()
{
	while (head_node != nullptr)
	{
		this->pop_front();
	}
}

template <typename T>
void List<T>::push_back(T data)
{
	Node<T>* New_Node = new Node<T>;
	New_Node->data = data;
	if (this->head_node == nullptr)
	{
		this->head_node = New_Node;
		this->tail_node = New_Node;
	}
	else
	{
		this->tail_node->ptr_to_next_node = New_Node;
		this->tail_node = New_Node;
	}
	this->size++;
}

template <typename T>
void List<T>::pop_front()
{
	if (this->tail_node != nullptr)
	{
		Node<T>* current_node = this->head_node;
		head_node = current_node->ptr_to_next_node;
		this->size--;
	}
}

template <typename T>
int List<T>::operator () ()
{
	return this->size;
}

template <typename T>
T& List<T>::operator[](int index)
{
	Node<T>* current_node = this->head_node;
	for (int i = 0; i != index; i++)
	{
		current_node = current_node->ptr_to_next_node;
	}
	return current_node->data;
}

template <typename T>
List<T>& List<T>::operator = (const List<T>& list)
{
	if (this != &list)
	{
		while (head_node != nullptr)
		{
			this->pop_front();
		}
		size = 0;
		Node<T>* current_node = list.head_node;
		while (current_node != nullptr)
		{
			push_back(current_node->data);
			current_node = current_node->ptr_to_next_node;
		}
	}
	return *this;
}

template <typename T>
List<T> List<T>::operator *(List<T>& list)
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
	List<T> temp_list(temp_size);
	for (int i = 0; i < temp_size; i++)
	{
		temp_list[i] = (*this)[i] * list[i];
	}
	return temp_list;
}