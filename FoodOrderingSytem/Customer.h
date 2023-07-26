#pragma once
#include "Order.h"
#include<string>
#include<iostream>
using namespace std;

class Customer
{
public:
	string name;
	int password;
	string telPhoneNumber;
	Order order;
	Customer();
	~Customer();
	Customer(string name, int password, string telPhoneNumber, Order order);
};