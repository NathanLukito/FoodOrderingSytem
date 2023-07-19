#pragma once
#include "User.h"
#include "Order.h"
#include "DoublyLinkedList.h"
#include<string>
#include<iostream>
using namespace std;

class Customer : public User
{
private:
	Order order;
public:
	Customer();
	~Customer();
	Customer(string name, int password, string telPhoneNumber, DoublyLinkedList orderList);
};