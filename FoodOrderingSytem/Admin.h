#pragma once
#include "LinkedList.h"
#include "FoodItem.h"
#include "Order.h"
#include "Queue.h"
#include <string>
#include <iostream>
//Name: Bi De
//S10239969D
//Group 1

using namespace std;

class Admin {
public:
	string name; 
	string password;
	string description;

	Admin();
	~Admin();
	Admin(string name, string password, string description);
	void displayMenu();
};