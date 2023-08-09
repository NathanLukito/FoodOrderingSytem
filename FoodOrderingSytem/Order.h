#pragma once
#include<string>
#include<iostream>
#include "OrderItem.h"
#include "LinkedList.h"
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
	string getOrderStatus();
	int getUserID();
	void printOrder();
	void remove(string name);
	void add(FoodItem foodItem);
	bool IsEmpty();
};