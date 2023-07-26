#pragma once

#include<string>
#include<iostream>
#include "Order.h"
using namespace std;

class User
{

public:
	int userID;
	string name;
	int password;
	string telPhoneNumber;
	Order order;
	User();
	~User();
	User(string name, int password, string telPhoneNumber);
	string getName();
	virtual void setName(string name);
	virtual void setPassword(int password);
	int getPassword();
};
