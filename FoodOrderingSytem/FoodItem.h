#pragma once
#include<string>
#include<iostream>
using namespace std;

class FoodItem
{	
public:
	int foodItemID;
	string foodItemName;
	string description;
	double price;
	FoodItem();
	~FoodItem();
	FoodItem(string foodItemName, string description, double price);
};
