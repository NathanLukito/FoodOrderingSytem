#pragma once
#include "User.h"
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

class Admin : public User {
public:
	Admin();
	~Admin();
	Admin(string name, int password, string telPhoneNumber);
};