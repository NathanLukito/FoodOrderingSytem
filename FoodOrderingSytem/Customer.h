#pragma once
#include "User.h"
#include "Order.h"
#include "DoublyLinkedList.h"
#include<string>
#include<iostream>
using namespace std;

class Customer : public User
{
private:
	DoublyLinkedList OrderList;
public:
	Customer();
	Customer(string name, int p, string telPhoneNumber, DoublyLinkedList OrderList);
	DoublyLinkedList getOrderList();
};