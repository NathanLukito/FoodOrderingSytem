#pragma once
#include "LinkedList.h"
#include "FoodItem.h"
#include "Order.h"
#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

class Admin {
public:
	string name; 
	string password;
	List<FoodItem> foodItemList;
	string description;
	Queue foodOrderList;
	string location;

	Admin();
	~Admin();
	Admin(string name, string password, string description);
	void displayMenu();
	void addFoodItem(FoodItem foodItem);
	void addOrder(Order order);
};