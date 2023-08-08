#pragma once
#include "OrderItem.h"
#include<string>
#include<iostream>
using namespace std;

OrderItem::OrderItem() {};
OrderItem::~OrderItem() {};

OrderItem::OrderItem(string name, int quantity, int OrderID)
{
	this->name = name;
	this->quantity = quantity;
	this->OrderID = OrderID;
}
/*
double OrderItem::getTotalPrice()
{
	return foodItem.price * quantity;
}
*/