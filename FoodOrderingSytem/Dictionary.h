#pragma once
#include <iostream>>
#include <string>
#include "Customer.h"
#include "LinkedList.h"
#define SIZE 100
using namespace std;

class Dictionary 
{
private:
	struct KeyValuePair
	{
		int key;
		List<Customer>* value;
		KeyValuePair* next;
	};
	KeyValuePair* table[SIZE];
public:
	Dictionary();
	~Dictionary();
	int hashFunction(string key);
	int checkUnique(string key);
	void insert(string key, Customer value);
	void print();
	Customer* findCustomer(string key, int password);
	void UpdateCustomer();
};

