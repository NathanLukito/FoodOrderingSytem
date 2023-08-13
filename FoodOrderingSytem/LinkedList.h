//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1

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
		T item;
		Node<T>* next;
	};
	Node<T>* firstNode = nullptr;	
	int  size;		

	//Constructor
	List()
	{
		size = 0;
		firstNode = nullptr;
	}

	//Destructor
	~List()
	{
		size = 0;
		firstNode = nullptr;
	}

	//Adds item to next node in list
	//Arguments: Object
	void add(T item)
	{
		struct Node<T>* temp = firstNode;
		struct Node<T>* node1 = new Node<T>;
		node1->item = item;
		node1->next = NULL;

		if (isEmpty())
		{
			firstNode = node1;
			size++;
			return;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = node1;
			size++;
			return;
		}
		temp = NULL;
		delete temp;
	}

	//Adds item to next Node of index in list
	//Arguments: index to insert next to, object
	void add(int index, T item)
	{
		struct Node<T>* temp = firstNode;
		struct Node<T>* node1 = new Node<T>;
		node1->next = NULL;
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
			node1->item = item;
			node1->next = temp->next;
			size++;
		}
		else
		{
			node1->item = item;
			node1->next = temp;
			firstNode = node1;
		}
		temp = NULL;
		delete temp;
	}

	//Remove item on index in list
	//Arguments: Index to remove from list
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

	//Get the Node of the index in the list
	//Arguments: Index of the Node to return in the list
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
			return temp;
		}
		temp = NULL;
		delete temp;
	}

	//Check if list is empty
	//Returns: bool
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

	//Return: size of list
	int getLength() { return size; }
};

