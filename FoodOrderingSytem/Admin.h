#pragma once
#include "User.h"
#include "LinkedList.h"
#include "FoodItem.h"
#include "Order.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Admin {
public:
	string name;
	int password;
	List<FoodItem> foodItemList;
	string description;
	List<Order> foodOrderList;

	Admin();
	~Admin();
	Admin(string name, int password, string description);
	void displayMenu();
	void addFoodItem(string foodItemName, string description, string category, double price);
	void addOrder(Order order);
};