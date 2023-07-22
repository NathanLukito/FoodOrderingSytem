#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

List::List() 
{ 
	size = 0;
	firstNode = nullptr;
}

List::~List() 
{ 
	size = 0;
	firstNode = nullptr;
}

bool List::add(ItemType item)
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

bool List::add(int index, ItemType item)
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

void List::remove(int index)
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

ItemType List::get(int index)
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

bool List::isEmpty()
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

int List::getLength() { return size; }

void List::print()
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


