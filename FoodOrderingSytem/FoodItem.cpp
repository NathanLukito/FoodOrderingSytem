#pragma once
#include "FoodItem.h"
#include<string>
#include<iostream>
using namespace std;

FoodItem::FoodItem() {};
FoodItem::~FoodItem() {};

FoodItem::FoodItem(string foodItemName, string description, double price)
{
	this->foodItemName = foodItemName;
	this->description = description;
	this->price = price;
}