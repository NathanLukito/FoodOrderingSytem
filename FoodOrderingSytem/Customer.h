#pragma once
#include "User.h"
#include "Order.h"
#include "DoublyLinkedList.h"
#include<string>
#include<iostream>
using namespace std;

class Customer : public User
{
public:
	Order order;
	Customer();
	~Customer();
	Customer(string name, int password, string telPhoneNumber, Order order);
};