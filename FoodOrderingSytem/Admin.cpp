#pragma once
#include "Admin.h"
#include <string>
#include <iostream>

using namespace std;

Admin::Admin() {};
Admin::~Admin() {};

Admin::Admin(string name, string password, string description, string location) {
	this->name = name;
	this->password = password;
	this->description = description;
	this->location = location;
}

void Admin::addFoodItem(FoodItem foodItem) {
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
	Queue orderList = this->foodOrderList;
	orderList.enqueue(order);
	cout << "Order added to " + this->name << endl;
}