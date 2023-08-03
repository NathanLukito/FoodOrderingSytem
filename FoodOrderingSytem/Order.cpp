#pragma once
#include "Order.h"
#include "OrderItem.h"
#include<string>
#include<list>
#include<iostream>
using namespace std;

Order::Order() {};
Order::~Order() {};

Order::Order(string orderStatus, list<OrderItem> orderItemList, string customerName)
{
	this->orderStatus = orderStatus;
	this->orderItemList = orderItemList;
	this->customerName = customerName;
}

double Order::getTotalPrice()
{
	double TotalPrice = 0;
	for(auto i : this->orderItemList)
	{
		TotalPrice += i.getTotalPrice();
	}
	return TotalPrice;
}

string Order::getOrderStatus()
{
	return orderStatus;
}

void Order::printOrder()
{
	if (orderItemList.empty())
	{
		cout << "Order is empty" << endl;
	}
	else
	{
		for (OrderItem i : this->orderItemList)
		{
			cout << i.foodItem.foodItemName << " x" << i.quantity << " : $" << getTotalPrice()<< endl;
		}
		cout << "Total Price = $" << getTotalPrice() << endl;
	}
}
void Order::remove(string name, int quantity)
{
	for (OrderItem& orderItem : this->orderItemList)
	{
		if (orderItem.foodItem.foodItemName == name)
		{
			if (orderItem.quantity >= quantity)
			{
				orderItem.quantity -= quantity;
				cout << "Order Item removed" << endl;
				if (orderItem.quantity == 0)
				{
					this->orderItemList.remove(orderItem);
					cout << "Order Item fully removed from list" << endl;
				}
				else
				{
					return;
				}
			}
		}
	}
	cout << "Order Item cannot be found" << endl;
	return;
}

void Order::add(FoodItem foodItem, int quantity)
{
	for (OrderItem& orderItem : this->orderItemList)
	{
		if (orderItem.foodItem.foodItemName == foodItem.foodItemName)
		{
			orderItem.quantity += quantity;
		}
	}

	this->orderItemList.push_back(OrderItem(foodItem, quantity));
	return;
}
