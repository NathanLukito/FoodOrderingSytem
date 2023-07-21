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
	Customer(Order order) : User(name, password, telPhoneNumber) {};
};