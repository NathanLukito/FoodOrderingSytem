#pragma once

#include<string>
#include<iostream>
using namespace std;

class User
{

public:
	int userID;
	string name;
	int password;
	string telPhoneNumber;
	User();
	~User();
	User(string name, int password, string telPhoneNumber);
	void setName(string name);
	void setPassword(int password);
	string getName();
	int getPassword();
};
