#pragma once
#include<string>
#include<iostream>
#include "DoublyLinkedList.h"
#include "OrderItem.h"
using namespace std;

class Order 
{
public:
	int orderID;
	string orderStatus;
	DoublyLinkedList<OrderItem> OrderItemList;
	int userID;
	Order();
	~Order();
	Order(int orderID, string orderStatus, DoublyLinkedList OrderItemList, int userID);
	double getTotalPrice();
	string getOrderStatus();
	int getUserID();
	void printOrder();
	DoublyLinkedList<OrderItem> getOrderItemList();
};