#pragma once
#include "Admin.h"
#include "User.h"
#include <string>
#include <iostream>

using namespace std;

Admin::Admin() {};
Admin::~Admin() {};

Admin::Admin(string name, int password, string telPhoneNumber) : User(name, password, telPhoneNumber) {
	this->name = name;
	this->password = password;
	this->telPhoneNumber = telPhoneNumber;
}