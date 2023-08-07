#pragma once
#include "Order.h"
#include<string>
#include<iostream>
using namespace std;

Order::Order() {};
Order::~Order() {};

Order::Order(string orderStatus, List<OrderItem> orderItemList, string customerName)
{
	this->orderStatus = orderStatus;
	this->orderItemList = orderItemList;
	this->customerName = customerName;
}

double Order::getTotalPrice()
{
	List<OrderItem>* list = &this->orderItemList;
	double TotalPrice = 0;
	List<OrderItem>::Node<OrderItem>* firstNode = list->get(0);
	while (firstNode->next != nullptr)
	{
		TotalPrice += firstNode->item.getTotalPrice();
		firstNode = firstNode->next;
	}
	return TotalPrice;
}

string Order::getOrderStatus()
{
	return orderStatus;
}

void Order::printOrder()
{
	List<OrderItem>* list = &this->orderItemList;
	List<OrderItem>::Node<OrderItem>* firstNode = list->get(0);
	while (firstNode->next != nullptr)
	{
		cout << "Name: " << firstNode->item.foodItem.foodItemName << " | x" << firstNode->item.quantity << " | Price: $" << firstNode->item.getTotalPrice();
		firstNode = firstNode->next;
	}
}
void Order::remove(string name)
{
	List<OrderItem>* list = &this->orderItemList;
	List<OrderItem>::Node<OrderItem>* firstNode = list->get(0);
	while (firstNode->next != nullptr)
	{
		if (firstNode->item.foodItem.foodItemName == name)
		{
			if (firstNode->item.quantity == 1)
			{
				firstNode = firstNode->next;
				cout << "Order Item removed" << endl;
			}
			else
			{
				firstNode->item.quantity -= 1;
				cout << "Order Item quantity is reduced by 1, new quantity is: " << firstNode->item.quantity << endl;
			}
		}
		firstNode = firstNode->next;
	}
	cout << "Order Item cannot be found" << endl;
	return;
}

void Order::add(FoodItem foodItem)
{
	List<OrderItem>* list = &this->orderItemList;
	List<OrderItem>::Node<OrderItem>* firstNode = list->get(0);
	int index = 0;
	while (firstNode->next != nullptr)
	{
		if (firstNode->item.foodItem.foodItemName == foodItem.foodItemName)
		{
			firstNode->item.quantity += 1;
			cout << "Order Item quantity increased by 1, new quantity is: " << firstNode->item.quantity << endl;
		}
		else
		{
			list->add(OrderItem(foodItem, 1));
			cout << "Order Item added" << endl;
		}
		firstNode = firstNode->next;
		index++;
	}
	cout << "Order Item cannot be found" << endl;
	return;
}
