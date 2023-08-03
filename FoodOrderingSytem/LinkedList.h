#pragma once
#include<string>
#include<iostream>
#include"Customer.h"
using namespace std;

typedef Customer ItemType;

class List
{
public:
	struct Node
	{
		ItemType item;	// item
		Node* next;	// pointer pointing to next item
	};
	Node* firstNode = nullptr;	// point to the first item
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

	bool add(ItemType item)
	{

		struct Node* temp = firstNode;
		struct Node* node1 = new Node;
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

	bool add(int index, ItemType item)
	{
		struct Node* temp = firstNode;
		struct Node* node1 = new Node;
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
		struct Node* temp = firstNode;
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

	ItemType get(int index)
	{
		struct Node* temp = firstNode;
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
			return temp->item;
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

	void print()
	{
		struct Node* temp = firstNode;
		while (temp != NULL)
		{
			cout << temp->item.name << endl;
			temp = temp->next;
		}
		temp = NULL;
		delete temp;
	}

	ItemType* getCustomer(int password)
	{
		struct Node* temp = firstNode;

		while (temp != nullptr)
		{
			if (temp->item.password == password)
			{
				return &temp->item;
			}
			temp = temp->next;
		}
		Customer* customer = new Customer();
		return customer;
	}
};

