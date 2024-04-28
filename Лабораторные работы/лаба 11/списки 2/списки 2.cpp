#include <iostream>
using namespace std;

int lenght_list;
struct Node
{
	char data;
	Node* ptr_next_node = nullptr;
	Node* ptr_previous_node = nullptr;
};

struct Double_List
{
	Node* head_node = nullptr;
	Node* tail_node = nullptr;

	void print_list()
	{
		if (head_node == nullptr)
		{
			cout << "Список пуст\n";
			return;
		}
		Node* current_node = head_node;
		do
		{
			cout << current_node->data << ' ';
			current_node = current_node->ptr_next_node;
		} while (current_node != tail_node->ptr_next_node);
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
			head_node = head_node->ptr_next_node;
			if (remove == tail_node)
			{
				tail_node = nullptr;
			}
			delete remove;
			lenght_list -= 1;
		}
	}
	void tail_push(const char& data, const int& index)
	{
		Node* new_node = new Node;
		new_node->data = data;

		new_node->ptr_previous_node = tail_node;
		if (tail_node != nullptr)
		{
			tail_node->ptr_next_node = new_node;
		}
		if (head_node == nullptr)
		{
			head_node = new_node;
		}
		tail_node = new_node;
		
	}
	void remove_element(const char& removed_element)
	{
		if (head_node->data == removed_element)
		{
			Node* remove_head = head_node;
			head_node = head_node->ptr_next_node;
			delete remove_head;
			lenght_list -= 1;
			return;
		}

		if (tail_node->data == removed_element)
		{
			Node* remove_tail = tail_node;
			tail_node = tail_node->ptr_previous_node;
			delete remove_tail;
			lenght_list -= 1;
			return;
		}

		Node* current_node = head_node->ptr_next_node;
		for (int i = 1; i < lenght_list-1; i++)
		{
			if (current_node->data == removed_element)
			{
				current_node->ptr_next_node->ptr_previous_node = current_node->ptr_previous_node;
				current_node->ptr_previous_node->ptr_next_node = current_node->ptr_next_node;
				delete current_node;
				lenght_list--;
				return;
			}
			current_node = current_node->ptr_next_node;
		}
	}
	bool is_element(const char& removed_element)
	{
		if (head_node == nullptr)
		{
			return 0;
		}
		Node* current_node = head_node;
		while (current_node != tail_node->ptr_next_node)
		{
			if (current_node->data == removed_element)
			{
				return 1;
			}
			current_node = current_node->ptr_next_node;
		}
		return 0;
	}
	void add_element(int& number_element, const char& data)
	{
		Node* new_node = new Node;
		new_node->data = data;
		if (number_element == 1)
		{
			new_node->ptr_next_node = head_node;
			head_node->ptr_previous_node = new_node;
			head_node = new_node;
			lenght_list += 1;
			return;
		}
		
		Node* current_node;
		if (number_element <= lenght_list / 2)
		{
			current_node = head_node;
			for (int i = 1; i < number_element-1; i++)
			{
				current_node = current_node->ptr_next_node;
			}
		}
		else
		{
			current_node = tail_node;
			for (int i = number_element-2; i < lenght_list-1; i++)
			{
				current_node = current_node->ptr_previous_node;
			}
		}
		new_node->ptr_next_node = current_node->ptr_next_node;
		current_node->ptr_next_node = new_node;
		new_node->ptr_next_node->ptr_previous_node = new_node;
		new_node->ptr_previous_node = current_node;
		lenght_list++;
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
	Double_List list;
	for (int i = 0; i < lenght_list; i++)
	{
		cout << "Введите символ: ";
		cin >> data;
		list.tail_push(data, i-1);
	}
	list.print_list();

	char removed_element;
	cout << "Какой элемент удалить? ";
	cin.seekg(cin.eof());
	cin >> removed_element;
	while (list.is_element(removed_element))
	{
		list.remove_element(removed_element);
		list.print_list();
	}
	
	if(lenght_list > 0) 
	{
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
	}

	list.remove_list();
	return 0;
}