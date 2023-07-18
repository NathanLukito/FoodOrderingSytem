#pragma once
#include<string>
#include<iostream>
#include "DoublyLinkedList.h"
using namespace std;

class Order 
{
private:
	int orderID;
	double totalPrice;
	string orderStatus;
	DoublyLinkedList OrderItemList;
	int userID;
public:
	Order();
	Order(int orderID, double totalPrice, string orderStatus, int userID);
	double getTotalPrice();
	double getOrderStatus();
	int getUserID();
	void printOrder();
};