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
	string category;
	double price;
	FoodItem();
	~FoodItem();
	FoodItem(string foodItemName, string description, string category, double price);
	void print();
};
