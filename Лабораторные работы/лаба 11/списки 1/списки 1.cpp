#include <iostream>
using namespace std;

int lenght_list;

struct Node
{
	char data;
	Node* next_node = nullptr;
};

struct List
{
	Node* head_node = nullptr;
	Node* tail_node = nullptr;

	void tail_push(const char& data)
	{
		Node* new_node = new Node;
		new_node->data = data;
		if (head_node == nullptr)
		{
			head_node = new_node;
			tail_node = new_node;
		}
		else
		{
			tail_node->next_node = new_node;
			tail_node = new_node;
		}
	}
	void print_list()
	{
		if (head_node == nullptr)
		{
			return;
		}
		Node* current_node = head_node;
		while (current_node != nullptr)
		{
			cout << current_node->data << ' ';
			current_node = current_node->next_node;
		}
		cout << '\n';
	}
	void remove_list()
	{
		if (head_node == nullptr)
		{
			return;
		}
		Node* remove;
		int n = lenght_list;
		for (int i = 0; i < n; i++)
		{
			remove = head_node;
			head_node = head_node->next_node;
			if (remove == tail_node)
			{
				tail_node = nullptr;
			}
			delete remove;
			lenght_list -= 1;
		}
	}
	void remove_element(char& removed_element)
	{
		if (head_node->data == removed_element)
		{
			Node* remove_head = head_node;
			head_node = head_node->next_node;
			delete remove_head;
			lenght_list -= 1;
			return;
		}
		Node* last_node = head_node;
		Node* current_node = last_node->next_node;
		while (current_node != nullptr)
		{
			if (current_node->data == removed_element)
			{
				if (current_node == tail_node)
				{
					tail_node = nullptr;
				}
				last_node->next_node = current_node->next_node;
				delete current_node;
				lenght_list -= 1;
				return;
			}
			current_node = current_node->next_node;
			last_node = last_node->next_node;
		}
		cout << "Такого элемента нет в списке\n";
	}
	void add_element(int& number_element, char& data)
	{
		Node* new_node = new Node;
		new_node->data = data;
		if (number_element == 1)
		{
			new_node->next_node = head_node;
			head_node = new_node;
			lenght_list += 1;
			return;
		}
		Node* current_node = head_node;
		for (int i = 1; i < number_element-1; i++)
		{
			current_node = current_node->next_node;
		}
		new_node->next_node = current_node->next_node;
		current_node->next_node = new_node;
		lenght_list += 1;
	}
};


int main()
{
	system("chcp 1251>null");
	char data;
	do
	{
		cout << "Размер списка: ";
		cin >> lenght_list;
	} while (lenght_list < 1);
	List list;
	for (int i = 0; i < lenght_list; i++)
	{
		cout << "Введите символ: ";
		cin >> data;
		list.tail_push(data);
	}
	list.print_list();
	char removed_element;
	cout << "Какой элемент удалить? ";
	cin.seekg(cin.eof());
	cin >> removed_element;
	list.remove_element(removed_element);
	list.print_list();
	int k, number_element;
	do
	{
		cout << "Сколько элементов добавить? ";
		cin >> k;
	} while (k < 0);
	do
	{
		cout << "Номер элемента, перед которым добавить: ";
		cin >> number_element;
	} while (number_element<1 || number_element > lenght_list);
	for (int i = 0; i < k; i++)
	{
		cout << "Введите элемент: ";
		cin >> data;
		int number_for_inserts = number_element + i;
		list.add_element(number_for_inserts, data);
	}
	list.print_list();

	list.remove_list();
	return 0;
}