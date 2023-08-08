#pragma once
#include "Admin.h"
#include <string>
#include <iostream>

using namespace std;

Admin::Admin() {};
Admin::~Admin() {};

Admin::Admin(string name, int password, string description) {
	this->name = name;
	this->password = password;
	this->description = description;
}

void Admin::addFoodItem(string foodItemName, string description, string category, double price) {
	FoodItem foodItem(foodItemName, description, category, price);
	List<FoodItem>* foodList = &this->foodItemList;
	foodList->add(foodItem);
	cout << "FoodItem added to " + this->name << endl;
	/*List<FoodItem>::Node<FoodItem>* firstNode = foodList->get(0);
	int index = 0;
	if (firstNode->next == nullptr) {
		foodList->add(foodItem);
	}
	else {
		List<FoodItem>::Node<FoodItem>* current = firstNode;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}*/
}

void Admin::addOrder(Order order) {
	List<Order>* orderList = &this->foodOrderList;
	orderList->add(order);
	cout << "Order added to " + this->name << endl;
}