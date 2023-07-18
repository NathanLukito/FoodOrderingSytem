#pragma once
#include<string>
#include<iostream>
#include "FoodItem.h"
using namespace std;

class OrderItem
{
private:
	FoodItem foodItem;
	int Quantity;
	double totalPrice;
public:
	OrderItem();
	OrderItem(FoodItem foodItem, int Quantity, double totalPrice);
	int getQuantity();
	double getTotalPrice();
};