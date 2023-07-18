#pragma once
#include<string>
#include<iostream>
#include "Order.h"

using namespace std;

typedef Order ItemType;
class Queue
{
private:
    struct Node
    {
        ItemType item;	// item
        Node* next;	// pointer pointing to next item
    };

public:
    Node* frontNode;	// point to the first item
    Node* backNode;	// point to the first item
    // constructor
    Queue();
    ~Queue();

    // enqueue (add) item at the back of queue
    void enqueue(ItemType item);

    // dequeue (remove) item from front of queue
    void dequeue();

    // dequeue (remove) and retrieve item from front of queue
    ItemType getdequeue();

    // retrieve (get) item from front of queue
    ItemType getFront();

    // check if the queue is empty
    bool isEmpty();

    // display items in queue from front to back
    void displayItems();

    int getLength();
};