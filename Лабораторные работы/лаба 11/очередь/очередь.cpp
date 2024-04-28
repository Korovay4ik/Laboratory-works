#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node* ptr_next_node = nullptr;
};

struct Queue
{
	int size_queue = 0;
	Node* head_node = nullptr;
	Node* tail_node = nullptr;

	void Push(const char& data)
	{
		Node* new_node = new Node;
		new_node->data = data;
		if (head_node == nullptr)
		{
			head_node = new_node;
			tail_node = new_node;
			size_queue++;
		}
		else
		{
			tail_node->ptr_next_node = new_node;
			tail_node = new_node;
			size_queue++;
		}
	}
	void Pop()
	{
		Node* remove = head_node;
		if (head_node!=nullptr)
		{
			head_node = head_node->ptr_next_node;
		}
		delete remove;
		size_queue--;
	}
	void print_queue()
	{
		if (head_node == nullptr)
		{
			cout << "Очередь пуста\n";
			return;
		}
		Node* current_node = head_node;
		while (current_node != nullptr)
		{
			cout << current_node->data << ' ';
			current_node = current_node->ptr_next_node;
		}
		cout << '\n';
	}
	void delete_queue()
	{
		if (head_node == nullptr)
		{
			return;
		}
		int n = size_queue;
		for (int i = 0; i < n; i++)
		{
			Pop();
		}
	}
	void remove_element(const char& key)
	{
		for (int i = 0; i < size_queue; i++)
		{
			if (head_node->data == key)
			{
				Pop();
				i--;
			}
			else
			{
				Push(head_node->data);
				Pop();
			}
		}
	}
	void add_element(int& number_element, int& k)
	{
		int i = 0;
		for (i; i < number_element-1; i++)
		{
			Push(head_node->data);
			Pop();
		}
		char data;
		for (int j = 1; j <= k; j++)
		{
			cout << "Введите " << j << "-й символ: ";
			cin >> data;
			Push(data);
		}
		for (i; i < size_queue - k; i++)
		{
			Push(head_node->data);
			Pop();
		}
	}
};

int main()
{
	system("chcp 1251>null");
	char data; int lenght_queue;
	do
	{
		cout << "Размер очереди: ";
		cin >> lenght_queue;
	} while (lenght_queue < 1);
	Queue queue;
	for (int i = 0; i < lenght_queue; i++)
	{
		cout << "Введите " << i+1 << "-й символ: ";
		cin >> data;
		queue.Push(data);
	}
	queue.print_queue();
	
	char removed_element;
	cout << "Какой элемент удалить? ";
	cin.seekg(cin.eof());
	cin >> removed_element;
	queue.remove_element(removed_element);
	queue.print_queue();
	
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
	} while (number_element<1 || number_element > queue.size_queue);
	queue.add_element(number_element, k);
	queue.print_queue();
	
	queue.delete_queue();
	return 0;
}