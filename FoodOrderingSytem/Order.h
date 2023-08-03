#pragma once
#include<string>
#include<iostream>
#include "OrderItem.h"
#include <list>
using namespace std;

class Order
{
public:
	int orderID;
	string orderStatus;
	list<OrderItem> orderItemList;
	string customerName;

	Order();
	~Order();
	Order(string orderStatus, list<OrderItem> orderItemList, string customerName);
	double getTotalPrice();
	string getOrderStatus();
	int getUserID();
	void printOrder();
	void remove(string name, int quantity);
	void add(FoodItem foodItem, int quantity);
};