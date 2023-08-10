#include "Dictionary.h"
#include "Customer.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
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

void Dictionary::insert(string key, Customer value)
{
    int index = hashFunction(key);
    if (checkUnique(key))
    {
        List<Customer>* CustomerList = new List<Customer>();
        Customer item;
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
            List<Customer>* list = table[i]->value;
            List<Customer>::Node<Customer>* firstNode = list->get(0);
            while (firstNode->next != nullptr)
            {
                cout << firstNode->item.name << endl;
                firstNode = firstNode->next;
            }
            cout << firstNode->item.name << endl;
        }
    }
}


Customer* Dictionary::findCustomer(string key, int password)
{
    if (checkUnique(key) == false)
    {
        List<Customer>* list = table[hashFunction(key)]->value;
        List<Customer>::Node<Customer>* firstNode = list->get(0);
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.password == password)
            {
                return &firstNode->item;
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.password == password)
        {
            return &firstNode->item;
        }
    }
    Customer* customer = new Customer();
    return customer;
}

void Dictionary::UpdateCustomer()
{
    ofstream clearFile("Customers.csv", ios::trunc);
    clearFile.close();
    bool check = false;
    ofstream File("Customers.csv", ios::app);
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != NULL)
        {
            List<Customer>* list = table[i]->value;
            List<Customer>::Node<Customer>* firstNode = list->get(0);
            while (firstNode->next != nullptr)
            {
                if (check)
                {
                    string customer = "\n" + firstNode->item.name + "," + to_string(firstNode->item.password) + "," + firstNode->item.telPhoneNumber;
                    File << customer;
                }
                else
                {
                    string customer = firstNode->item.name + "," + to_string(firstNode->item.password) + "," + firstNode->item.telPhoneNumber;
                    File << customer;
                    check = true;
                }
                firstNode = firstNode->next;
            }
            
        }
    }
    File.close();
}
