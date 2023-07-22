#pragma once
#include<string>
#include<iostream>
#include "DoublyLinkedList.h"
#include "OrderItem.h"
#include <list>
using namespace std;

class Order
{
public:
	int orderID;
	string orderStatus;
	list<OrderItem> orderItemList;
	int userID;

	Order();
	~Order();
	Order(int orderID, string orderStatus, list<OrderItem> orderItemList, int userID);
	double getTotalPrice();
	string getOrderStatus();
	int getUserID();
	void printOrder();
};