#pragma once
#include "Customer.h"
#include "Order.h"
#include "OrderItem.h"
#include<string>
#include<iostream>
using namespace std;

Customer::Customer() {};
Customer::~Customer() {};

Customer::Customer(string name, int password, string telPhoneNumber, DoublyLinkedList orderList)
{
	string name = name;
	int password = password;
	string telPhoneNumber = telPhoneNumber;
	DoublyLinkedList orderList = orderList;
}


