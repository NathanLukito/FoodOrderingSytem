#pragma once
#include "User.h"
#include "Order.h"
#include <queue>
#include<string>
#include<iostream>
using namespace std;

class Customer : public User
{
private:
	queue<Order> OrderList;
};