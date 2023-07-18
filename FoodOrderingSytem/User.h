#pragma once

#include<string>
#include<iostream>
using namespace std;

class User
{
private:
	int userID;
	string name;
	int password;
	string telPhoneNumber;

public:
	User();
	User(string name, int p);
	void setName(string n);
	void setPassword(int p);
	string getName();
	int getPassword();
};
