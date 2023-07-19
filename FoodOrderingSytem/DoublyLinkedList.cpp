#include "Order.h"
#include "DoublyLinkedList.h"
#include "OrderItem.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() 
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() 
{
    while (head != nullptr) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(T data) 
{
    Node<T>* new_node = new Node<T>();
    new_node->data = data;
    new_node->prev = nullptr;
    new_node->next = head;

    if (head != nullptr) {
        head->prev = new_node;
    }

    head = new_node;
}

template <typename T>
void DoublyLinkedList<T>::remove(T data) 
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        if (current->data == data) 
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else 
            {
                head = current->next;
            }

            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::print() 
{
    Node<T>* current = head;
    if (typeid(current).name() == "OrderItem")
    {
        while (current != nullptr)
        {
            cout << current->data.FoodItem.FoodItemName << " | Quantity: " << current->data.Quantity << " | Price: " << current->data.getTotalPrice() << endl;
            current = current->next;
        }
        cout << endl;
    }
    else
    {
        while (current != nullptr))
        {
            {
                cout << current->data.name << " | Telephone Number: " << current->data.telPhoneNumber << endl;
                current = current->next;
            }
        }
        cout << endl;
    }
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() 
{
    if (head->data == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
double DoublyLinkedList<T>::getTotalPrice()
{
    Node<T>* current = head;
    double totalPrice = 0;
    while (current != nullptr)
    {
        totalPrice += current->data.getTotalPrice();
        current = current->next;
    }
    return totalPrice;
}