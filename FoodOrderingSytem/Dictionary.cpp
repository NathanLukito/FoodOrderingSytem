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
        List<Customer>* list = table[index]->value;
        List<Customer>::Node<Customer>* firstNode = list->get(0);
        while (firstNode != nullptr)
        {
            if (firstNode->item.password == value.password)
            {
                cout << "Password has been taken by another user" << endl;
                return;
            }
            firstNode = firstNode->next;
        }
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
    ofstream File("Customers.csv", ios::out | ios::trunc);
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != NULL)
        {
            List<Customer>* list = table[i]->value;
            List<Customer>::Node<Customer>* firstNode = list->get(0);
            while (firstNode->next != nullptr)
            {
                string customer = firstNode->item.name + "," + to_string(firstNode->item.password) + "," + firstNode->item.telPhoneNumber + "," + to_string(firstNode->item.orderID);
                File << customer << endl;
                firstNode = firstNode->next;
            }
            string customer = firstNode->item.name + "," + to_string(firstNode->item.password) + "," + firstNode->item.telPhoneNumber + "," + to_string(firstNode->item.orderID);
            File << customer << endl; 
        }
    }
    File.close();
}


