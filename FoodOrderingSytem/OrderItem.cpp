#pragma once
#include "OrderItem.h"
#include<string>
#include<iostream>
using namespace std;

OrderItem::OrderItem() {};
OrderItem::~OrderItem() {};

OrderItem::OrderItem(FoodItem foodItem, int quantity)
{
	this->foodItem = foodItem;
	this->quantity = quantity;
}

double OrderItem::getTotalPrice()
{
	return foodItem.price * quantity;
}