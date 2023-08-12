#pragma once
#include "OrderItem.h"
#include<string>
//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1

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