//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1
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
	int orderID;
	Customer();
	~Customer();
	Customer(string name, int password, string telPhoneNumber, int orderID);
	void print();
};