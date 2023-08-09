#pragma once
#include "FoodItem.h"
#include<string>
#include<iostream>
#include <iomanip>
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
	string name = "Name: " + this->foodItemName;
	string category = "Category: " + this->category;
	string price = "Price: " + to_string(this->price);
	cout << left << setw(30) << name << left << setw(20) << category << left << setw(20) << price << endl;
}