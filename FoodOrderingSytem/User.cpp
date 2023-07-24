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

void User::setName(string name)
{
	this->name = name;
}
void User::setPassword(int password)
{
	this->password = password;
}
