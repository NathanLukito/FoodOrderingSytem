#pragma once
#include<string>
#include<iostream>
#include "LinkedList.h"
#include "FoodItem.h"
#include "Order.h"
#include <list>
#ifndef RESTAURANT_H
#define RESTAURANT_H
using namespace std;

class Restaurant {
public:
	string restaurantName;
	list<FoodItem> foodItem;
	string description;
	list<Order> foodOrder;

	Restaurant();
	~Restaurant();
	Restaurant(string restaurantName, string description);
	void addFoodItem(string itemName, string description, double price);
	void displayMenu();
	void addOrder(const Order& order);
	list<FoodItem>* searchCategory(string category);
	FoodItem* searchName(string name);
};
#endif // RESTAURANT_H