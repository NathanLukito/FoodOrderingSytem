#include "Dictionary.h"
#include "Customer.h"
#include "DoublyLinkedList.h"
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
    return hash%100;
}

int Dictionary::checkUnique(string key)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != NULL)
        {
            if (table[i]->key == hashFunction(key))
            {
                return false;
            }
        }
    }
    return true;
}

void Dictionary::insert(string key, User value)
{
    int index = hashFunction(key);
    if (checkUnique(key))
    {
        List* CustomerList = new List();
        ItemType item;
        KeyValuePair* keyValuePair = new KeyValuePair();
        CustomerList->add(value);
        keyValuePair->key = index;
        keyValuePair->value = CustomerList;
        keyValuePair->next = nullptr;
        table[index] = keyValuePair;
    }
    else
    {
        table[index]->value->add(value);
    }
}

void Dictionary::print()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != NULL)
        {
            table[i]->value->print();
        }
    }
}

User Dictionary::findUser(string key, int password)
{
    if (checkUnique(key) == false)
    {
        return table[hashFunction(key)]->value->getUser(password);
    }
    cout << "User cannot be found" << endl;
    return User();
}