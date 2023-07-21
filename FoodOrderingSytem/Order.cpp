#pragma once
#include "Order.h"
#include "OrderItem.h"
#include<string>
#include<iostream>
using namespace std;

Order::Order() {};
Order::~Order() {};

Order::Order(int orderID, string orderStatus, DoublyLinkedList<OrderItem> orderItemList, int userID)
{
	this->orderID = orderID;
	this->orderStatus = orderStatus;
	this->orderItemList = orderItemList;
	this->userID = userID;
}

double Order::getTotalPrice()
{
	return this->orderItemList.getTotalPrice();
}

string Order::getOrderStatus()
{
	return orderStatus;
}

int Order::getUserID()
{
	return userID;
}
void Order::printOrder()
{
	if (this->orderItemList.isEmpty())
	{
		cout << "Order is empty" << endl;
	}
	else
	{
		this->orderItemList.print();
	}
}
