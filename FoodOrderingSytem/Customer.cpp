//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1
#pragma once
#include "Order.h"
#include "Customer.h"
#include<string>
#include<iostream>
#include<iomanip>>
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

void Customer::print()
{
	string name = "Name: " + this->name;
	string telPhoneNumber = "Contact: " + this->telPhoneNumber;
	cout << left << setw(20) << name << left << setw(20) << telPhoneNumber << endl;
}


