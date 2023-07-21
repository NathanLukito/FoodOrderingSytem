#include "User.h"
#include<string>
#include<iostream>
using namespace std;
User::User() {};
User::~User() {};

User::User(string name, int p, string telPhoneNumber)
{
	this->name = name;
	this->password = password;
	this->telPhoneNumber = telPhoneNumber;
}

void setName(string name)
{
	name = name;
}
void setPassword(int password)
{
	password = password;
}
