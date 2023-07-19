#pragma once
#include<string>
#include<iostream>
#include "Order.h"
using namespace std;

template <typename T>
T data;
struct Node
{
    struct Node* prev;
    struct Node* next;
};

template <typename T>
class DoublyLinkedList 
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert(T data);
    void remove(T data);
    void print();
    bool isEmpty();
    double getTotalPrice();

private:
    Node<T>* head;
    Node<T>* tail;
};