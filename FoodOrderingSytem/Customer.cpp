#pragma once
#include "Order.h"
#include "Customer.h"
#include<string>
#include<iostream>
using namespace std;

Customer::Customer() {};
Customer::~Customer() {};

Customer::Customer(string name, int password, string telPhoneNumber, int orderID)
{
	this->name = name;
	this->password = password;
	this->telPhoneNumber = telPhoneNumber;
	this->orderID = orderID;
}


