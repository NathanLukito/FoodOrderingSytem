#pragma once
#include<string>
#include<iostream>
#include "OrderItem.h"
using namespace std;

class Order
{
public:
	int OrderID;
	string orderStatus;
	string customerName;

	Order();
	~Order();
	Order(int OrderID, string orderStatus, string customerName);
	double getTotalPrice();
	void modifyOrderStatus(string orderStatus);
	int getUserID();
	void printOrder();
	void remove(string name);
	void add(FoodItem foodItem);
	bool IsEmpty();
};