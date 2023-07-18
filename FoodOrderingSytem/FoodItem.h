#pragma once
#include<string>
#include<iostream>
using namespace std;

class FoodItem
{
private:
	int foodItemID;
	string foodItemName;
	string description;
	double price;
public:
	FoodItem();
	FoodItem(int foodItemID, string foodItemName);
	string getName();
	string getDescription();
	string getPrice();

};
