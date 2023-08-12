//Name: Nathan Farrel Lukito
//StudentID: S10244400
//Group: 1

#pragma once
#include<string>
#include<iostream>
using namespace std;

class FoodItem
{	
public:
	string foodItemName;
	string description;
	string category;
	double price;
	string adminName;

	FoodItem();
	~FoodItem();
	FoodItem(string foodItemName, string description, string category, double price, string adminName);
	void print();
};
