#pragma once
#include <iostream>>
#include <string>
#include "User.h"
#include "DoublyLinkedList.h"
#define SIZE 100
using namespace std;

class Dictionary 
{
private:
	struct KeyValuePair
	{
		int key;
		List* value;
		KeyValuePair* next;
	};
	KeyValuePair* table[SIZE];
public:
	Dictionary();
	~Dictionary();
	int hashFunction(string key);
	int checkUnique(string key);
	void insert(string key, User value);
	void print();
	User* findUser(string key, int password);
};

