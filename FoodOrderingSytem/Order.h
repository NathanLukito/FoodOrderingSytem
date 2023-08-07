#pragma once
#include<string>
#include<iostream>
#include "OrderItem.h"
#include "LinkedList.h"
using namespace std;

class Order
{
public:
	int orderID;
	string orderStatus;
	List<OrderItem> orderItemList;
	string customerName;

	Order();
	~Order();
	Order(string orderStatus, List<OrderItem> orderItemList, string customerName);
	double getTotalPrice();
	string getOrderStatus();
	int getUserID();
	void printOrder();
	void remove(string name);
	void add(FoodItem foodItem);
};