//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1

#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {};
Queue::~Queue() {};

//Adds item to the back of the list
//Arguments: Item
void Queue::enqueue(ItemType item)
{
	struct Node* node = new Node;
	node->item = item;

	if (isEmpty() == true)
	{
		frontNode = node;
		backNode = node;
	}
	else
	{
		backNode->next = node;
		backNode = node;
	}
}

//Removed item from front of list
void Queue::dequeue()
{
	if (frontNode == backNode)
	{
		frontNode = nullptr;
		backNode = nullptr;
	}
	else
	{
		struct Node* temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
	}
}

//Return dequeued item
ItemType Queue::getdequeue()
{
	struct Node* temp = frontNode;
	frontNode = frontNode->next;
	return temp->item;
}

//get first item in list
//Return Item
ItemType Queue::getFront()
{
	return frontNode->item;
}

//Check if list is empty
//Return bool
bool Queue::isEmpty()
{
	if (frontNode == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Display all items in queue
void Queue::displayItems()
{
	struct Node* temp = frontNode;
	while (temp != backNode)
	{
		cout << temp->item.OrderID << temp->item.customerName << temp->item.orderStatus << endl;
		temp = temp->next;
	}
	cout << temp->item.OrderID << " " << temp->item.customerName << " " << temp->item.orderStatus << endl;
	temp = nullptr;
	delete temp;
}

//Get the length og queue
int Queue::getLength()
{
	struct Node* temp = frontNode;
	int length = 0;
	while (temp != backNode)
	{
		length++;
		temp = temp->next;
	}
	length++;
	temp = nullptr;
	delete temp;
	return length;
}