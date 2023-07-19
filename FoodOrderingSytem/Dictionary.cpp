#include "Dictionary.h"
#include "Customer.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary()
{
	for (int i = 0; i < SIZE; i++)
	{
		table[i] = nullptr;
	}
}

Dictionary::~Dictionary()
{
    for (int i = 0; i < SIZE; i++)
    {
        while (table[i] != nullptr)
        {
            KeyValuePair* temp = table[i];
            table[i] = table[i]->next;
            delete temp;
        }
    }
}

int Dictionary::hashFunction(string key)
{
    int hash = 0;
    for (char letter : key)
    {
        hash = 256 * hash + letter;
    }
    return hash;
}

int Dictionary::checkUnique(string key)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i]->key == hashFunction(key))
        {
            return false;
        }
    }
    return true;
}

void Dictionary::insert(string key, Customer value)
{
    int index = hashFunction(key);
    if (checkUnique(key))
    {
        DoublyLinkedList<Customer>* CustomerList = new DoublyLinkedList<Customer>;
        CustomerList->insert(value);
        table[index] = new KeyValuePair;
        table[index]->key = index;
        table[index]->value = CustomerList;
        table[index]->next = nullptr;
    }
    else
    {
        table[index]->value->insert(value);
    }
}