#ifndef LIST_H
#define LIST_H

#include <string>
#include "Restaurant.h"
using namespace std;

struct Node
{
	Restaurant restaurant;
	Node* next;	// pointer pointing to next item
	Node(const Restaurant& restaurant);
};

class LinkedList
{
private:

	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	LinkedList();			// constructor

	~LinkedList();		// destructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	void addRestaurant(const Restaurant& restaurant);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the list
	void print();

	// void replace(int index, ItemType item);
	// int search(ItemType item);

	Restaurant* findRestaurantByName(string name);

	void dynamicSearch(string option, string searchString, list<FoodItem>* foodItems, Restaurant* restaurant, FoodItem* foodItem);
};
#endif // LIST_H