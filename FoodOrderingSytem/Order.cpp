//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1

#pragma once
#include "Order.h"
#include<string>
#include<iostream>
using namespace std;

Order::Order() {};
Order::~Order() {};

Order::Order(int OrderID, string orderStatus, string customerName, string adminName)
{
	this->OrderID = OrderID;
	this->orderStatus = orderStatus;
	this->customerName = customerName;
	this->adminName = adminName;
}

void Order::modifyOrderStatus(string orderStatus)
{
	this->orderStatus = orderStatus;
}