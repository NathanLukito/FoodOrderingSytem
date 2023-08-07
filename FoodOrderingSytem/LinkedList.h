#pragma once
#include<string>
#include<iostream>
using namespace std;

template <typename T>
class List
{
public:
	template <typename T>
	struct Node
	{
		T item;	// item
		Node<T>* next;	// pointer pointing to next item
	};
	Node<T>* firstNode = nullptr;	// point to the first item
	int  size;		// number of items in the list
	// constructor
	List()
	{
		size = 0;
		firstNode = nullptr;
	}

	~List()
	{
		size = 0;
		firstNode = nullptr;
	}

	bool add(T item)
	{

		struct Node<T>* temp = firstNode;
		struct Node<T>* node1 = new Node<T>;
		node1->item = item;
		node1->next = NULL;

		if (isEmpty())
		{
			firstNode = node1;
			size++;
			return false;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = node1;
			size++;
			return true;
		}
		temp = NULL;
		delete temp;
	}

	bool add(int index, T item)
	{
		struct Node<T>* temp = firstNode;
		struct Node<T>* node1 = new Node<T>;
		node1->next = NULL;
		if (index > size)
		{
			cout << "index out of range" << endl;
			return false;
		}
		else if (index != 0)
		{
			for (int i = 1; i < index; i++)
			{
				if (temp->next != NULL)
				{
					temp = temp->next;
				}
			}
			node1->item = item;
			node1->next = temp->next;
			size++;
			return true;
		}
		else
		{
			node1->item = item;
			node1->next = temp;
			firstNode = node1;
			return true;
		}
		temp = NULL;
		delete temp;
	}

	void remove(int index)
	{
		struct Node<T>* temp = firstNode;
		if (index > size)
		{
			cout << "index out of range" << endl;
		}
		else if (index != 0)
		{
			for (int i = 1; i < index; i++)
			{
				if (temp->next != NULL)
				{
					temp = temp->next;
				}
			}
			temp->next = temp->next->next;
			size--;
		}
		else
		{
			firstNode = temp->next;
			size--;
		}
		temp = NULL;
		delete temp;
	}

	Node<T>* get(int index)
	{
		struct Node<T>* temp = firstNode;
		if (index > size)
		{
			cout << "index out of range" << endl;
		}
		else if (index != 0)
		{
			for (int i = 1; i < index; i++)
			{
				if (temp->next != NULL)
				{
					temp = temp->next;
				}
			}
			return temp;
		}
		else
		{
			firstNode = temp->next;
		}
		temp = NULL;
		delete temp;
	}

	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getLength() { return size; }

};

