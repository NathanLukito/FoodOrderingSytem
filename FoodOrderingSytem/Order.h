#pragma once
#include<string>
#include<iostream>
using namespace std;

class Order 
{
private:
	int orderID;
	double totalPrice;
	string orderStatus;
	int userID;
public:
	Order();
	Order(int orderID, double totalPrice, string orderStatus, int userID);
	double getTotalPrice();
	double getOrderStatus();
	int getUserID();
};