#pragma once
#include<string>
#include<iostream>
#include "Order.h";

using namespace std;
typedef Order ItemType;

class Queue
{
private:
    struct Node
    {
        ItemType item;
        Node* next;
    };

public:
    Node* frontNode;
    Node* backNode;
    Queue();
    ~Queue();
    void enqueue(ItemType item);
    void dequeue();
    ItemType getdequeue();
    ItemType getFront();
    bool isEmpty();
    void displayItems();
    int getLength();
};