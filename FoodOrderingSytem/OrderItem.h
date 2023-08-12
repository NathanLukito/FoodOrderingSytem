#pragma once
#include<string>
#include<iostream>
#include "FoodItem.h"
using namespace std;

class OrderItem
{
public:
	string name;
	int quantity;
	int OrderID;
	OrderItem();
	~OrderItem();
	OrderItem(string name, int quantity, int OrderID);
};