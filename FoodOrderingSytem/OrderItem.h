#pragma once
#include<string>
#include<iostream>
#include "FoodItem.h"
using namespace std;

class OrderItem
{
public:
	FoodItem foodItem;
	int quantity;
	OrderItem();
	~OrderItem();
	OrderItem(FoodItem foodItem, int quantity);
	double getTotalPrice();
};