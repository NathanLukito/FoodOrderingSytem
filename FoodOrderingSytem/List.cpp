#include "List.h"
#include "Restaurant.h"
using namespace std;

Node::Node(const Restaurant& restaurant) : restaurant(restaurant), next(nullptr) {}

LinkedList::LinkedList() : firstNode(nullptr) {}

LinkedList::~LinkedList() {
	Node* current = firstNode;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void LinkedList::addRestaurant(const Restaurant& restaurant) {
	Node* newNode = new Node(restaurant);
	if (firstNode == nullptr) {
		firstNode = newNode;
	}
	else {
		Node* current = firstNode;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
}

void LinkedList::remove(int index) {
	if (index < 0 || index >= size)
		return;

	if (index == 0) {
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
	else {
		Node* current = firstNode;
		for (int i = 0;i < index - 1;i++) {
			current = current->next;
		}
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
	}

	size--;
}

bool LinkedList::isEmpty() {
	return (size == 0);
}

int LinkedList::getLength() {
	return size;
}

void LinkedList::print() {
	Node* current = firstNode;
	while (current != nullptr) {
		std::cout << "Restaurant Name: " << current->restaurant.restaurantName << "\n";
		// Add other attributes you want to print here (e.g., description, food items, etc.)
		current = current->next;
	}
}

Restaurant* LinkedList::findRestaurantByName(string name) {
	Node* current = firstNode;
	while (current != nullptr) {
		if (current->restaurant.restaurantName == name) {
			return &(current->restaurant);
		}
		current = current->next;
	}
	return nullptr; // Restaurant not found
}


void LinkedList::dynamicSearch(string option, string searchString, list<FoodItem>* foodItems, Restaurant* restaurant, FoodItem* foodItem)
{
	if (option == "1")
	{
		//restaurant search
		Node* current = firstNode;
		while (current != nullptr) {
			if (current->restaurant.restaurantName == searchString) {
				*restaurant = current->restaurant;
				return;
			}
			current = current->next;
		}
		cout << "No restaurants with the name: " << searchString << " found" << endl;
		return;
	}
	else if (option == "2")
	{
		//foodname search
		Node* current = firstNode;
		while (current != nullptr) {
			FoodItem* searchItem = current->restaurant.searchName(searchString);
			if (searchItem->foodItemName == searchString) 
			{
				foodItem = searchItem;
				return;
			}
			current = current->next;
		}
	}
	else if (option == "3")
	{
		//category search
		Node* current = firstNode;
		while (current != nullptr)
		{
			list<FoodItem>* searchedFoodItems = current->restaurant.searchCategory(searchString);
			foodItems->assign(searchedFoodItems->begin(), searchedFoodItems->end());
			current = current->next;
		}
	}
}
