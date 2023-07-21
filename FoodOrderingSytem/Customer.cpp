#pragma once
#include "Customer.h"
#include "Order.h"
#include "OrderItem.h"
#include "Customer.h"
#include "User.h"
#include<string>
#include<iostream>
using namespace std;

Customer::Customer() {};
Customer::~Customer() {};

Customer::Customer(Order order) : User(name, password, telPhoneNumber)
{
	this->name = name;
	this->password = password;
	this->telPhoneNumber = telPhoneNumber;
	this->order = order;
}


