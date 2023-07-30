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

Restaurant::Restaurant(string restaurantName, string description) {
	this->restaurantName = restaurantName;
	this->description = description;
}

void Restaurant::addFoodItem(string itemName, string description, double price) {
	FoodItem item;
	item.foodItemName = itemName;
	item.description = description;
	item.price = price;
	foodItem.push_back(item);
}

void Restaurant::displayMenu() {
	cout << "Menu for " << restaurantName << ":\n";
	for (const auto& item : foodItem) {
		cout << item.foodItemName << " - $" << item.price << "\n" << item.description << "\n";
	}
}

void Restaurant::addOrder(const Order& order) {
	foodOrder.push_back(order);
}