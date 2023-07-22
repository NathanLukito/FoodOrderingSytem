#pragma once
#include<string>
#include<iostream>
#include "DoublyLinkedList.h"
#include "FoodItem.h"
#include "Order.h"
#include <list>
using namespace std;

class Restaurant {
public:
	int restaurantID;
	string restaurantName;
	list<FoodItem> foodItemList;
	string description;
	list<Order> foodOrderList;

	Restaurant();
	~Restaurant();
	Restaurant(int restaurantID, string restaurantName, list<FoodItem> foodItemList, string description, list<Order> foodOrderList);

};
