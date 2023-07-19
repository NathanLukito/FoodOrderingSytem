#include "Order.h"
#include "DoublyLinkedList.h"
#include "OrderItem.h"
#include <iostream>
#include <string>

using namespace std;
DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

void DoublyLinkedList::insert(Order data) {
    struct node* new_node = new struct node;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL) {
        head->prev = new_node;
    }

    head = new_node;
}

void DoublyLinkedList::remove(Order data) {
    struct node* current = head;

    while (current != NULL) 
    {
        if (current->data == data) 
        {
            if (current->prev != NULL) 
            {
                current->prev->next = current->next;
            }
            else 
            {
                head = current->next;
            }

            if (current->next != NULL) 
            {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }
}

void DoublyLinkedList::print() 
{
    struct node* current = head;

    while (current != NULL) 
    {
        cout << current->data.FoodItem.getName() << " | Quantity: " << current->data.getQuantity << " | Price: " << current->data.getTotalPrice() << endl;
        current = current->next;
    }

    cout << endl;
}

bool DoublyLinkedList::isEmpty() 
{
    if (head->data == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double DoublyLinkedList::getTotalPrice()
{
    struct node* current = head;
    double totalPrice = 0;
    while (current != NULL)
    {
        totalPrice += current->data.getTotalPrice();
        current = current->next;
    }
    return totalPrice;
}