//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1
//The insert function allows users with the same name and places them in the same linked list, same passwords will be rejected
//I am assuming that it is more proabable that the user will have a same name than a same password

#include "Dictionary.h"
#include "Customer.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

//Constructor
Dictionary::Dictionary()
{
	for (int i = 0; i < SIZE; i++)
	{
		table[i] = nullptr;
	}
}

//Destructor
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

//Hashes name into a key
//Arguments: Name
//Return: key
int Dictionary::hashFunction(string key)
{
    int hash = 0;
    for (char letter : key)
    {
        hash = 256 * hash + letter;
    }
    return hash%100;
}

//Checks if username is in dictionary
//Arguments: name
//Return: bool
bool Dictionary::checkUnique(string key)
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

//Hashes name and uses it as the key, linkedlist of Customer objects is used as value, inserts the key and value as a keyvaluepair into pointer based dictionary
//Arguments: name, customer
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

//Displays all customers is all linkedlists in all keyvaluepairs
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

//Find customer based on name and password
//Arguments: name, password
//Return: Customer
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

//Clears Customers csv file, updates file with current data
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


