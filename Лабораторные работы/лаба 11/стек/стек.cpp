#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node* ptr_next_node = nullptr;
};

struct Stack
{
	Node* head_node = nullptr;
	int stack_size = 0;

	void Push(const char& data)
	{
		Node* new_node = new Node;
		new_node->data = data;
		new_node->ptr_next_node = head_node;
		head_node = new_node;
		stack_size++;
	}

	void delete_stack()
	{
		if (head_node == nullptr)
		{
			return;
		}
		int n = stack_size;
		for (int i = 0; i < n; i++)
		{
			Pop();
			stack_size--;
		}
	}

	void print_stack()
	{
		if (head_node == nullptr)
		{
			cout << "Стек пуст\n";
			return;
		}
		Node* current_node = head_node;
		Stack stack_tmp;
		for (int i = 0; i < stack_size; i++)
		{
			stack_tmp.Push(current_node->data);
			current_node = current_node->ptr_next_node;
		}
		current_node = stack_tmp.head_node;
		for (int i = 0; i < stack_size; i++)
		{
			cout << current_node->data << ' ';
			current_node = current_node->ptr_next_node;
			stack_tmp.Pop();
		} 
		cout << '\n';
	}

	void Pop()
	{
		if (head_node == nullptr)
		{
			return;
		}
		Node* remove = head_node;
		head_node = head_node->ptr_next_node;
		delete remove;
		stack_size--;
	}

	void delete_element(const char& key)
	{
		Stack stack_tmp;
		while (head_node != nullptr)
		{
			if (head_node->data == key)
			{
				Pop();
			}
			else
			{
				stack_tmp.Push(head_node->data);
				Pop();
			}
		}
		while (stack_tmp.head_node != nullptr)
		{
			Push(stack_tmp.head_node->data);
			stack_tmp.Pop();
		}
	}
	void add_element(int& number_element, char* data2, int& k)
	{
		Stack stack_tmp;
		int n = stack_size;
		for (int i = 0; i < n-number_element; i++)
		{
			stack_tmp.Push(head_node->data);
			Pop();
		}
		for (int i = 0; i < k; i++)
		{
			Push(data2[i]);
		}

		while (stack_tmp.head_node != nullptr)
		{
			Push(stack_tmp.head_node->data);
			stack_tmp.Pop();
		}
	}
};

int main()
{
	system("chcp 1251>NULL");
	int lenght;
	char data;
	do
	{
		cout << "Введите длину стека: ";
		cin >> lenght;
	} while (lenght < 1);
	Stack stack;
	for (int i = 0; i < lenght; i++)
	{
		cout << i + 1 << "-ый элемент стека: ";
		cin >> data;
		stack.Push(data);
	}
	stack.print_stack();

	char key;
	cout << "Введите элемент, который нужно удалить: ";
	cin.seekg(cin.eof());
	cin >> key;
	stack.delete_element(key);
	stack.print_stack();

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
	} while (number_element<1 || number_element > stack.stack_size);
	number_element--;
	char* data2 = new char[k];
	for (int i = 0; i < k; i++)
	{
		cout << "Введите " << i + 1 << "-й элемент: ";
		cin >> data2[i];
	}
	stack.add_element(number_element, data2, k);
	stack.print_stack();

	delete[]data2;
	stack.delete_stack();
	return 0;
}