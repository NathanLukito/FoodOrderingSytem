#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {};
Queue::~Queue() {};

void Queue::enqueue(ItemType item)
{
	struct Node* node = new Node;
	node->item = item;

	if (isEmpty() == false)
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

void Queue::dequeue()
{
	if (frontNode == backNode)
	{
		frontNode = NULL;
		backNode = NULL;
	}
	else
	{
		struct Node* temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
	}
}

ItemType Queue::getdequeue()
{
	struct Node* temp = frontNode;
	frontNode = frontNode->next;
	return temp->item;
}

ItemType Queue::getFront()
{
	return frontNode->item;
}

bool Queue::isEmpty()
{
	if (frontNode == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Queue::displayItems()
{
	struct Node* temp = frontNode;
	while (temp != backNode)
	{
		cout << temp->item.userID << endl;
		temp = temp->next;
	}
	cout << temp->item.userID << endl;
	temp = NULL;
	delete temp;
}

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
	temp = NULL;
	delete temp;
	return length;
}