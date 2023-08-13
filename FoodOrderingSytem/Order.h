//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1
// Order Statuses
//0: No Order
//1 : Unsent Order
//2 : Currently Preparing
//3 : Waiting for Pickup
//4 : Order Failed

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
	string adminName;

	Order();
	~Order();
	Order(int OrderID, string orderStatus, string customerName, string adminName);
	void modifyOrderStatus(string orderStatus);
};