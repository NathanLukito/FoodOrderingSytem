#pragma once
#include "Order.h"
#include "OrderItem.h"
#include<string>
#include<iostream>
using namespace std;

Order::Order() {};
Order::~Order() {};

Order::Order(int orderID, string orderStatus, DoublyLinkedList orderItemList, int userID)
{
	int orderID = orderID;
	string orderStatus = orderStatus;
	DoublyLinkedList orderItemList = orderItemList;
	int userID = userID;
}

double Order::getTotalPrice()
{
	return OrderItemList.getTotalPrice();
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
	if (OrderItemList.isEmpty())
	{
		cout << "Order is empty" << endl;
	}
	else
	{
		OrderItemList.print();
	}
}
