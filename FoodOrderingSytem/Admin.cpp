#pragma once
#include "Admin.h"
#include <string>
#include <iostream>

using namespace std;

Admin::Admin() {};
Admin::~Admin() {};

Admin::Admin(string name, string password, string description) {
	this->name = name;
	this->password = password;
	this->description = description;
}
