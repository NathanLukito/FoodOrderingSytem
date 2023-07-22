#pragma once
#include<string>
#include<iostream>
#include "Restaurant.h"
#include "FoodItem.h"
#include "Order.h"
#include <list>
using namespace std;

Restaurant::Restaurant() {};
Restaurant::~Restaurant() {};

Restaurant::Restaurant(int restaurantID, string restaurantName, list<FoodItem> foodItemList, string description, list<Order> foodOrderList) {
	this->restaurantID = restaurantID;
	this->restaurantName = restaurantName;
	this->foodItemList = foodItemList;
	this->description = description;
	this->foodOrderList = foodOrderList;
}