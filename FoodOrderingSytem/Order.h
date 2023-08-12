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