#pragma once
#include <iostream>>
#include <string>
#include "Customer.h"
#include "DoublyLinkedList.h"
#define SIZE 5
using namespace std;

typedef DoublyLinkedList<Customer>* ItemType;

class Dictionary 
{
private:
	struct KeyValuePair
	{
		int key;
		ItemType value;
		KeyValuePair* next;
	};
	KeyValuePair* table[SIZE];
public:
	Dictionary();
	~Dictionary();
	int hashFunction(string key);
	int checkUnique(string key);
	void insert(string key, Customer value);
};

