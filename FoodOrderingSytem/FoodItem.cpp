#pragma once
#include "FoodItem.h"
#include<string>
#include<iostream>
using namespace std;

FoodItem::FoodItem() {};
FoodItem::~FoodItem() {};

FoodItem::FoodItem(string foodItemName, string description, string category, double price, string adminName)
{
	this->foodItemName = foodItemName;
	this->description = description;
	this->category = category;
	this->price = price;
	this->adminName = adminName;
}

void FoodItem::print()
{
	cout << "Name: " << this->foodItemName << "\nCategory: " << this->category << "\n\nDescription:\n" << this->description << "\n\nPrice: $" << this->price << endl;
}