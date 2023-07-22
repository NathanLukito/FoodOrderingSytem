#pragma once
#include "Order.h"
#include "OrderItem.h"
#include<string>
#include<list>
#include<iostream>
using namespace std;

Order::Order() {};
Order::~Order() {};

Order::Order(int orderID, string orderStatus, list<OrderItem> orderItemList, int userID)
{
	this->orderID = orderID;
	this->orderStatus = orderStatus;
	this->orderItemList = orderItemList;
	this->userID = userID;
}

double Order::getTotalPrice()
{
	double TotalPrice = 0;
	for(auto i : this->orderItemList)
	{
		TotalPrice += i.getTotalPrice();
	}
	return TotalPrice;
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
	if (this->orderItemList.empty())
	{
		cout << "Order is empty" << endl;
	}
	else
	{
		for (OrderItem i : this->orderItemList)
		{
			cout << i.foodItem.foodItemName << " x" << i.quantity << " : $" << getTotalPrice()<< endl;
		}
	}
}
