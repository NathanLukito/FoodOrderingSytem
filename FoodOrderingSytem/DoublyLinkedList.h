#pragma once
#include<string>
#include<iostream>
#include "Order.h"
using namespace std;

typedef Order ItemType;
class DoublyLinkedList {
private:
    struct node
    {
        ItemType data;
        struct node* prev;
        struct node* next;
    };
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert(Order data);
    void remove(Order data);
    void print();

private:
    struct node* head;
};