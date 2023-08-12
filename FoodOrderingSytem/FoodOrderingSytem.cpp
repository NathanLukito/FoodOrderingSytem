#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
#include "List.h" 
#include "LinkedList.h"
#include "Restaurant.h"
#include "FoodItem.h"
#include "Admin.h"
#include "Order.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Dictionary Customers;
List<Order> Orders;
List<OrderItem> OrderItems;
List<FoodItem> FoodItems;
List<Admin> Admins;

string redundantBuffer = "\n_______________________________________________________________________________________________\n";

//Name: Nathan
//Clear cin to avoid inputs being skipped due to invalid input
void cinClear()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

//Name: Nathan
//Adds customers to Customers dictionary from Customers csv file
void init_customers()
{
    ifstream File("Customers.csv");
    string line;
    while (getline(File,line))
    {
        stringstream ss(line);
        string name;
        string password;
        string telPhoneNumber;
        string orderID;
        getline(ss, name, ',');
        if (name == "")
        {
            break;
        }
        getline(ss, password, ',');
        getline(ss, telPhoneNumber, ',');
        getline(ss, orderID, ',');
        Customers.insert(name, Customer(name, stoi(password), telPhoneNumber, stoi(orderID)));
    }
    File.close();
}

//Name: Nathan
//Adds orders to Orders list from Orders csv file
void init_orders()
{
    ifstream File("Orders.csv");
    string line;
    while (getline(File, line))
    {
        stringstream ss(line);
        string OrderID;
        string orderStatus;
        string customerName;
        string adminName;
        getline(ss, OrderID, ',');
        if (OrderID == "")
        {
            break;
        }
        getline(ss, orderStatus, ',');
        getline(ss, customerName, ',');
        getline(ss, adminName, ',');
        Orders.add(Order(stoi(OrderID), orderStatus, customerName, adminName));
    }
    File.close();
}

//Name: Nathan
//Adds orderItems to OrderItems list from OrderItems csv file
void init_orderItems()
{
    ifstream File("OrderItems.csv");
    string line;
    while (getline(File, line))
    {
        stringstream ss(line);
        string name;
        string quantity;
        string OrderID;
        getline(ss, name, ',');
        if (name == "")
        {
            break;
        }
        getline(ss, quantity, ',');
        getline(ss, OrderID, ',');
        OrderItems.add(OrderItem(name, stoi(quantity), stoi(OrderID)));
    }
    File.close();
}

//Name: Nathan
//Adds admins to Admins list from Admins csv file
void init_admins()
{
    ifstream File("Admins.csv");
    string line;
    while (getline(File, line))
    {
        stringstream ss(line);
        string name;
        string password;
        string description;
        getline(ss, name, ',');
        if (name == "")
        {
            break;
        }
        getline(ss, password, ',');
        getline(ss, description, ',');
        Admins.add(Admin(name, password, description));
    }
    File.close();
}

//Name: Nathan
//Adds foodItems to FoodItems list from FoodItems csv file
void init_fooditems()
{
    ifstream File("FoodItems.csv");
    string line;
    while (getline(File, line))
    {
        stringstream ss(line);
        string foodItemName;
        string description;
        string category;
        string price;
        string adminName;
        getline(ss, foodItemName, ',');
        if (foodItemName == "")
        {
            break;
        }
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, price, ',');
        getline(ss, adminName, ',');
        FoodItems.add(FoodItem(foodItemName, description, category, stod(price), adminName));
    }
    File.close();
}

//Name: Nathan
//Calls all initializer functions
void init_Data()
{
    init_customers();
    init_orders();
    init_orderItems();
    init_admins();
    init_fooditems();
}

//Name: Nathan
//Calls update_customers function from Customers dictionary
void update_customers()
{
    Customers.UpdateCustomer();
}

//Name: Nathan
//Clears Orders csv file and updates it with current data
void update_orders()
{
    ofstream File("Orders.csv", ios::out | ios::trunc);
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            string Order = to_string(firstNode->item.OrderID) + "," + firstNode->item.orderStatus + "," + firstNode->item.customerName + "," + firstNode->item.adminName;
            File << Order << endl;
            firstNode = firstNode->next;
        }
        string Order = to_string(firstNode->item.OrderID) + "," + firstNode->item.orderStatus + "," + firstNode->item.customerName + "," + firstNode->item.adminName;
        File << Order << endl;
    }
    File.close();
}

//Name: Nathan
//Clears OrderItems csv file and updates it with current data
void update_orderItems()
{
    ofstream File("OrderItems.csv", ios::out | ios::trunc);
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            string orderItem = firstNode->item.name + "," + to_string(firstNode->item.quantity) + "," + to_string(firstNode->item.OrderID);
            File << orderItem << endl;
            firstNode = firstNode->next;
        }
        string orderItem = firstNode->item.name + "," + to_string(firstNode->item.quantity) + "," + to_string(firstNode->item.OrderID);
        File << orderItem << endl;
    }
    File.close();
}

//Name: Nathan
//Clears Admins csv file and updates it with current data
void update_admins()
{
    ofstream File("Admins.csv", ios::out | ios::trunc);
    List<Admin>::Node<Admin>* firstNode = Admins.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            string admin = firstNode->item.name + "," + firstNode->item.password + "," + firstNode->item.description;
            File << admin << endl;
            firstNode = firstNode->next;
        }
        string admin = firstNode->item.name + "," + firstNode->item.password + "," + firstNode->item.description;
        File << admin << endl;
        firstNode = firstNode->next;
    }
    File.close();
}

//Name: Nathan
//Clears FoodItems csv file and updates it with current data
void update_fooditems()
{
    ofstream File("FoodItems.csv", ios::out | ios::trunc);
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            string foodItem = firstNode->item.foodItemName + "," + firstNode->item.description + "," + firstNode->item.category + "," + to_string(firstNode->item.price) + "," + firstNode->item.adminName;
            File << foodItem << endl;
            firstNode = firstNode->next;
        }
        string foodItem = firstNode->item.foodItemName + "," + firstNode->item.description + "," + firstNode->item.category + "," + to_string(firstNode->item.price) + "," + firstNode->item.adminName;
        File << foodItem << endl;
    }
    File.close();
}

//Name:Nathan
//Calls all update functions
void update_Data()
{
    update_customers();
    update_orders();
    update_orderItems();
    update_fooditems();
    update_admins();
}

//Name:Nathan
//Changes order status
//Arguments: OrderID, status
void modifyOrderStatus(int OrderID, string status)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == OrderID)
            {
                firstNode->item.orderStatus = status;
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.OrderID == OrderID)
        {
            firstNode->item.orderStatus = status;
        }
    }
}

//Name: Nathan
//Changes order adminName
//Arguments: OrderID, restaurant name
void modifyOrderRestaurant(int OrderID, string restaurant)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == OrderID)
            {
                firstNode->item.adminName = restaurant;
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.OrderID == OrderID)
        {
            firstNode->item.adminName = restaurant;
        }
    }
}

//Name: Nathan
//Uses selection sort to recursively loop through orders list to find customer order
//Arguments: customer, firstNode of Orders list
//Return: Order
Order recursiveGetOrder(Customer* customer, List<Order>::Node<Order>*firstNode)
{
    if (firstNode->next != nullptr)
    {
        if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
        {
            return firstNode->item;
        }
        return recursiveGetOrder(customer, firstNode->next);
    }
    if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
    {
        return firstNode->item;
    }
    cout << redundantBuffer << endl;
    cout << "Order could not be found" << endl;
    cout << redundantBuffer << endl;
}

//Name: Nathan
//Calls recursiveGetOrder
//Arguments: customer
//Return: Order
Order getOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    return recursiveGetOrder(customer,firstNode);
}

//Name: Nathan
//Finds the price of the foodItem and multiplies it by the quantity of the orderItem
//Arguments: orderItem
//Return: price of orderItem
int getOrderItemPrice(OrderItem orderItem)
{
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    double totalPrice = 0;
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.foodItemName == orderItem.name)
            {
                totalPrice += firstNode->item.price;
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.foodItemName == orderItem.name)
        {
            totalPrice += firstNode->item.price;
        }
        totalPrice += firstNode->item.price;
    }
    return totalPrice*orderItem.quantity;
}

//Name: Nathan
//Display orderItems in the order
//Arguments: order
void printOrder(Order order)
{
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    bool check = false;
    double totalPrice = 0;
    cout << redundantBuffer << endl;
    if (firstNode != nullptr && order.orderStatus != "0")
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == order.OrderID)
            {
                check = true;
                double orderItemPrice = getOrderItemPrice(firstNode->item);
                totalPrice += orderItemPrice;
                cout << firstNode->item.name << " | x" << firstNode->item.quantity << " | Price: $" << orderItemPrice << endl;
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.OrderID == order.OrderID)
        {
            check = true;
            double orderItemPrice = getOrderItemPrice(firstNode->item);
            totalPrice += orderItemPrice;
            cout << firstNode->item.name << " | x" << firstNode->item.quantity << " | Price: $" << orderItemPrice << endl;
        }
        cout << "Restaurant: " << order.adminName << endl;
    }
    else
    {
        cout << "\n Order is empty" << endl;
    }
    if (order.orderStatus == "2")
    {
        cout << "\nStatus: Order is being prepared" << endl;
    }
    else if (order.orderStatus == "3")
    {
        cout << "\nStatus: Order is waiting to be completed" << endl;
    }
    else if (order.orderStatus == "3")
    {
        cout << "\nStatus: Order has been failed" << endl;
    }
    else
    {
        cout << "\nTotal Price: $" << totalPrice << endl;
    }
    cout << redundantBuffer << endl;
}

void printStore(Admin store) {
    cout << redundantBuffer << endl;
    cout << store.name << " " << store.description << endl;
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.adminName == store.name) 
            {
                cout << firstNode->item.foodItemName << " " << firstNode->item.price << endl;
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.adminName == store.name) {
            cout << firstNode->item.foodItemName << " " << firstNode->item.price << endl;
        }
    }
    cout << redundantBuffer << endl;
}

//Name: Nathan
//Removes the orderItem from OrderItems list;
//Arguments: name of OrderItem, customer
void removeOrderItem(string name, Customer* customer)
{
    Order order = getOrder(customer);
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    int index = 0;
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.name == name && firstNode->item.OrderID == order.OrderID && firstNode->item.OrderID == customer->orderID)
            {
                if (firstNode->item.quantity != 1)
                {
                    firstNode->item.quantity -= 1;
                    return;
                }
                else
                {
                    OrderItems.remove(index);
                    return;
                }
            }
            index++;
            firstNode = firstNode->next;
        }
        if (firstNode->item.name == name && firstNode->item.OrderID == order.OrderID && firstNode->item.OrderID == customer->orderID)
        {
            if (firstNode->item.quantity != 1)
            {
                firstNode->item.quantity -= 1;
                return;
            }
            else
            {
                OrderItems.remove(index);
                return;
            }
        }
    }
}

//Name: Nathan
//Clears all orderItems linked to the customer
//Arguments: customer
void clearOrder(Customer* customer)
{
    List<Order>::Node<Order>* temp = Orders.get(0);
    Order* tempOrder = new Order;
    if (temp != nullptr)
    {
        while (temp->next != nullptr)
        {
            if (temp->item.customerName == customer->name && temp->item.OrderID == customer->orderID)
            {
                temp->item.orderStatus = "0";
                tempOrder = &temp->item;
            }
            temp = temp->next;
        }
        if (temp->item.customerName == customer->name && temp->item.OrderID == customer->orderID)
        {
            temp->item.orderStatus = "0";
            temp->item.adminName = "";
            tempOrder = &temp->item;
        }
    }
    else
    {
        cout << "There are no Orders" << endl;
    }
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    int index = 0;
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == tempOrder->OrderID)
            {
                OrderItems.remove(index);      
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.OrderID == tempOrder->OrderID)
        {
            OrderItems.remove(index);
        }
    }
}

//Name: Nathan
//User inputs name and password
//Return: customer
Customer* loginAccount()
{
    cout << "Enter your name: " << endl;
    string Name;
    cin >> Name;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter a password: " << endl;
    int Password;
    cin >> Password;
    cin.clear();
    cin.ignore(10000, '\n');
    return Customers.findCustomer(Name, Password);
}

//Name: Nathan
//User inputs user details, new customer is added to customers list, new order is added to orders list
void createAccount()
{
    cout << "Enter your name: " << endl;
    string Name;
    cin >> Name;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter a password: " << endl;
    int Password;
    cin >> Password;
    cout << "Enter your phone number: " << endl;
    string telPhoneNum;
    cin >> telPhoneNum;
    cin.clear();
    cin.ignore(10000, '\n');
    //Assume 1 customer has only 1 order and can only do 1 order
    Customers.insert(Name, Customer(Name, Password, telPhoneNum, Orders.size + 1));
    Orders.add(Order(Orders.size + 1, "0", Name, ""));
}

//Name: Nathan
//User inputs name of orderItem, calls remove orderItem
//Arguments: customer
void removeItemMenu(Customer* customer)
{
    while (true)
    {
        cout << "Type the name of the item you want removed or 'exit' to exit this menu" << endl;
        string name;
        cin >> name;
        cinClear();
        if (name == "exit")
        {
            return;
        }
        else
        {
            removeOrderItem(name, customer);
            printOrder(getOrder(customer));
        }
    }
}

//Name: Nathan
//Display foodItems from the restaurant chosen
//Arguments: restaurant name
void printFoodItems(string restaurant)
{
    cout << redundantBuffer << endl;
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.adminName == restaurant)
            {
                firstNode->item.print();
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.adminName == restaurant)
        {
            firstNode->item.print();
        }
    }
    cout << redundantBuffer << endl;
}

//Name: Nathan
//Finds if the category has been duplicated in Categories list
//Arguments: Categories list, category
//Return: bool
bool isDuplicate(List<string>Categories, string category)
{
    List<string>::Node<string>* firstNode = Categories.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item == category)
            {
                return true;
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item == category)
        {
            return true;
        }
    }
    return false;
}

//Name: Nathan
//Prints all categories from a restaurant
//Arguments: restaurant name
//Return: List of categories
List<string>* printCategories(string restaurant)
{
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    List<string> Categories;
    if (firstNode != nullptr)
    {
        cout << redundantBuffer << "Categories" << redundantBuffer<< endl;
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.adminName == restaurant)
            {
                if (!isDuplicate(Categories, firstNode->item.category))
                {
                    cout << "[ " << firstNode->item.category << " ]" << endl;
                    Categories.add(firstNode->item.category);
                }
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.adminName == restaurant)
        {
            if (!isDuplicate(Categories, firstNode->item.category))
            {
                cout << "[ " << firstNode->item.category << " ]" << endl;
                Categories.add(firstNode->item.category);
            }
        }
    }
    return &Categories;
}

//Name: Nathan
//Prints all categories from a restaurant
//Arguments: category, restaurant name
void printFoodfromCat(string category, string restaurant)
{
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    if (firstNode != nullptr)
    {
        cout << redundantBuffer << endl;
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.category == category && firstNode->item.adminName == restaurant)
            {
                firstNode->item.print();
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.category == category && firstNode->item.adminName == restaurant)
        {
            firstNode->item.print();
        }
        cout << redundantBuffer << endl;
    }
}

//Name: Nathan
//If there is orderItem in order, add 1 to the quantity, else add new orderItem to OrderItems list
//Arguments: foodname, OrderID
//Return: bool
bool addOrderItemDuplicate(string foodName, int OrderID)
{
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    while (firstNode->next != nullptr)
    {
        if (firstNode->item.name == foodName && firstNode->item.OrderID == OrderID)
        {
            firstNode->item.quantity++;
            return true;
        }
        firstNode = firstNode->next;
    }
    if (firstNode->item.name == foodName && firstNode->item.OrderID == OrderID)
    {
        firstNode->item.quantity++;
        return true;
    }
    return false;
}

//Name: Nathan
//User inputs name of food, finds order and calls addOrderItemDuplicate
//Arguments: customer, category, restaurant name
void addItemMenu(Customer* customer, string categoryOption, string restaurant)
{
    while (true)
    {
        bool check = false;
        printFoodfromCat(categoryOption, restaurant);
        Order order = getOrder(customer);
        printOrder(order);
        cout << redundantBuffer << endl;
        cout << "Type the name of the food you want or type 'exit' to exit" << endl;
        cout << redundantBuffer << endl;
        string foodChoice;
        cin >> foodChoice;
        cinClear();
        if (foodChoice == "exit")
        {
            return;
        }
        else
        {
            List <FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
            
            while (firstNode->next != nullptr)
            {
                if (firstNode->item.foodItemName == foodChoice && firstNode->item.adminName == restaurant)
                {
                    check = true;
                    if (!addOrderItemDuplicate(foodChoice, order.OrderID))
                    {
                        OrderItems.add(OrderItem(foodChoice, 1, order.OrderID));
                        if (order.orderStatus == "0")
                        {
                            modifyOrderStatus(order.OrderID, "1");
                        }
                    }
                }
                firstNode = firstNode->next;
            }
            if (firstNode->item.foodItemName == foodChoice && firstNode->item.adminName == restaurant)
            {
                check = true;
                if (!addOrderItemDuplicate(foodChoice, order.OrderID))
                {
                    OrderItems.add(OrderItem(foodChoice, 1, order.OrderID));
                }
            }
            if (!check)
            {
                cout << redundantBuffer << endl;
                cout << "Food not found" << endl;
                cout << redundantBuffer << endl;
            }
        }
    }
}

//Name: Nathan
//User inputs category, calls addItemMenu
//Arguments custoemr
void chooseCategory(Customer* customer)
{
    string restaurant = getOrder(customer).adminName;
    printCategories(restaurant);
    cout << redundantBuffer << "Type the name of the category you want to choose" << redundantBuffer << endl;
    string categoryOption;
    cin >> categoryOption;
    cinClear();
    addItemMenu(customer, categoryOption, restaurant);
}


//Name: Nathan
//Displays all restaurants in Admins list
void printRestaurants()
{
    List<Admin>::Node<Admin>* firstNode = Admins.get(0);
    if (firstNode != nullptr)
    {
        cout << redundantBuffer << endl;
        while (firstNode->next != nullptr)
        {
            cout << "[" << firstNode->item.name << "]" << endl;
            firstNode = firstNode->next;
        }
        cout << "[" << firstNode->item.name << "]" << endl;
    }
}

//Name: Nathan
//User inputs name of restaurant, calls modifyOrderRestaurant to set the restaurant
//Arguments: order
//Return: string
string chooseRestaurant(Order order)
{
    while (true)
    {
        printRestaurants();
        cout << redundantBuffer << endl;
        cout << "Type the name of the restaurant you want or 'exit' to exit" << endl;
        cout << redundantBuffer << endl;
        string restaurantOption;
        cin >> restaurantOption;
        cinClear();
        if (restaurantOption == "exit")
        {
            return "exit";
        }
        List<Admin>::Node<Admin>* firstNode = Admins.get(0);
        if (firstNode != nullptr)
        {
            while (firstNode->next != nullptr)
            {
                if (firstNode->item.name == restaurantOption)
                {
                    modifyOrderRestaurant(order.OrderID, restaurantOption);
                    return restaurantOption;
                }
            }
            if (firstNode->item.name == restaurantOption)
            {
                modifyOrderRestaurant(order.OrderID, restaurantOption);
                return restaurantOption;
            }
        }
        cout << redundantBuffer << endl;
        cout << "Restaurant not found" << endl;
        cout << redundantBuffer << endl;
    }
}

//Name: Nathan
//User chooses which search type to use
//Arguments: customer
void searchItemMenu(Customer* customer)
{
    Order order = getOrder(customer);
    string restaurantOption = "";
    while (true)
    {
        if (order.adminName == "")
        {
            if (getOrder(customer).adminName == "")
            {
                restaurantOption = chooseRestaurant(order);
            }

            if (restaurantOption == "exit")
            {
                return;
            }
        }
        cout << redundantBuffer << endl;
        cout << "1) Search restaurant (Will clear Order)\n2) Search food name\n3) Search Category\n4) Cancel" << endl;
        cout << redundantBuffer << endl;
        string searchOption;
        cin >> searchOption;
        cinClear();
        if (searchOption == "1")
        {
            clearOrder(customer);
            restaurantOption = chooseRestaurant(order);
            if (restaurantOption == "exit")
            {
                return;
            }
        }
        else if (searchOption == "2")
        {
            printFoodItems(order.adminName);
            //searchFoodItemMenu();
        }
        else if (searchOption == "3")
        {
            chooseCategory(customer);
        }
        else if (searchOption == "4")
        {
            return;
        }
    }
}

//Name: Nathan
//Changes orderstatus to 2
//Arguments: customer
void sendOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
            {
                firstNode->item.orderStatus = "2";
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
        {
            firstNode->item.orderStatus = "2";
        }
    }
    cout << redundantBuffer << endl;
    cout << "Order sent, currently preparing order... ... " << endl;
    cout << redundantBuffer << endl;
}

//Name: Nathan
//Changes orderstatus to 1
//Arguments: customer
void cancelOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
            {
                firstNode->item.orderStatus = "1";
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
        {
            firstNode->item.orderStatus = "1";
        }
    }
    cout << redundantBuffer << endl;
    cout << "Order Cancelled" << endl;
    cout << redundantBuffer << endl;
}

//Name: Nathan
//Display collect order message
void acceptOrderMessage()
{
    cout << redundantBuffer << endl;
    cout << "Your food has been prepared, please collect your food" << endl;
    cout << "Once you have collected the food, accept the order on the system" << endl;
    cout << redundantBuffer << endl;
}

//Name: Nathan
//Changes orderstatus to 0, clear order
//Arguments: customer
void acceptOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
            {
                firstNode->item.orderStatus = "0";
            }
            firstNode = firstNode->next;
        }
        if (firstNode->item.customerName == customer->name && firstNode->item.OrderID == customer->orderID)
        {
            firstNode->item.orderStatus = "0";
        }
    }
    clearOrder(customer);
    cout << redundantBuffer << endl;
    cout << "Order Accepted" << endl;
    cout << redundantBuffer << endl;
}

//Name: Nathan
//Menu displayed is changed based on orderstatus, allows user to modify order if applicable
//Arguments: customer
void orderMenu(Customer* customer)
{
    string orderOption;
    string menuArray[5] = { "1) Go back\n2) Add Items", "1) Go back\n2) Remove Items\n3) Add Items\n4) Clear Order\n5) Send Order", "1) Go back\n2) Cancel Order", "1) Go back\n2) Accept Order", "1) Go back\n2) Resolved"};
    Order order = getOrder(customer);
    while (true)
    {
        string orderStatus = order.orderStatus;
        if (orderStatus == "0")
        {
            cout << redundantBuffer << endl;
            cout << menuArray[0] << endl;
            cout << redundantBuffer << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if (orderOption == "2")
            {
                printOrder(order);
                searchItemMenu(customer);
                printOrder(order);
            }
        }
        else if (orderStatus == "1")
        {
            cout << redundantBuffer << endl;
            cout << menuArray[1] << endl;
            cout << redundantBuffer << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if (orderOption == "2")
            {
                printOrder(order);
                removeItemMenu(customer);
                printOrder(order);
            }
            else if (orderOption == "3")
            {
                printOrder(order);
                searchItemMenu(customer);
                printOrder(order);
            }
            else if (orderOption == "4")
            {
                clearOrder(customer);
                cout << "Order Cleared" << endl;
                return;
            }
            else if (orderOption == "5")
            {
                sendOrder(customer);
                printOrder(order);
            }
            return;
        }
        else if(orderStatus == "2")
        {
            cout << redundantBuffer << endl;
            cout << menuArray[2] << endl;
            cout << redundantBuffer << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if(orderOption == "2")
            {
                printOrder(order);
                cancelOrder(customer);
                printOrder(order);
            }
        }
        else if (orderStatus == "3")
        {
            cout << redundantBuffer << endl;
            cout << menuArray[3] << endl;
            cout << redundantBuffer << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if (orderOption == "2")
            {
                printOrder(order);
                acceptOrderMessage();
                acceptOrder(customer);
            }
        }
        else if (orderStatus == "4")
        {
            cout << redundantBuffer << endl;
            cout << menuArray[4];
            cout << "Your order has been cancelled by the restaurant, go to the " << order.adminName<<  " to find out more" << endl;
            cout << redundantBuffer << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if(orderOption == "2")
            {
                clearOrder(customer);
                cout << "Order has been cleared" << endl;
            }
            printOrder(order);
            
        }
    }
}

//Name: Nathan
//Allow user to choose to go searchItemMenu or orderMenu
//Arguments: customer
void customerMenu(Customer* customer)
{
    while (true)
    {
        cout << redundantBuffer << endl;
        cout << "1) Search for food\n2) View Order\n3) Logout" << endl;
        cout << redundantBuffer << endl;
        string accountOption;
        cin >> accountOption;
        cinClear();
        if (accountOption == "1")
        {
            searchItemMenu(customer);
        }
        else if (accountOption == "2")
        {
            printOrder(getOrder(customer));
            orderMenu(customer);
        }
        else if (accountOption == "3")
        {
            cout << redundantBuffer << endl;
            cout << "Logged Out" << endl;
            cout << redundantBuffer << endl;
            return;
        }
        else
        {
            cout << redundantBuffer << endl;
            cout << "Enter a valid option" << endl;
            cout << redundantBuffer << endl;
        }
    }
    return;
}

void printAdminOrders(Admin admin) {
    Queue adminOrders = admin.foodOrderList;
    adminOrders.displayItems();
}

string AccountType() {
    cout << redundantBuffer << endl;
    cout << "1) Customer\n2) Admin\n3) Exit" << endl;
    cout << redundantBuffer << endl;
    string accountType;
    cin >> accountType;
    cin.clear();
    cin.ignore(10000, '\n');
    return accountType;
}

string AdminMenu() {
    cout << redundantBuffer << endl;
    cout << "1) Update status\n2) View order information" << endl;
    cout << redundantBuffer << endl;
    string adminOption;
    cin >> adminOption;
    cin.clear();
    cin.ignore(10000, '\n');
    return adminOption;
}

Admin findAdmin(string name, string password) {
    /*List<Admin>::Node<Admin>* leftNode = Admins.get(0);
    List<Admin>::Node<Admin>* rightNode = nullptr;

    int length = 0;
    List<Admin>::Node<Admin>* temp = Admins.get(0);
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    while (leftNode != rightNode) {
        int middleIndex = (length - 1) / 2;
        int count = 0;
        List<Admin>::Node<Admin>* middleNode = leftNode;
        while (count < middleIndex) {
            middleNode = middleNode->next;
            count++;
        }

        if (middleNode->item.name == name && middleNode->item.password == password) {
            return true;
        }
        else if ()
    }*/

    for (int store = 0; store < Admins.getLength(); store++) {
        List<Admin>::Node<Admin>* storeNode = Admins.get(store);
        Admin restaurant = storeNode->item;
        if (restaurant.name == name && restaurant.password == password) {
            Admin admin = storeNode->item;
            return admin;
        }
        else {
            storeNode = storeNode->next;
        }
    }
}

Admin adminLogin() {
    cout << "Enter your name: " << endl;
    string Name;
    cin >> Name;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter your password: " << endl;
    string Password;
    cin >> Password;
    cin.clear();
    cin.ignore(10000, '\n');

    Admin admin = findAdmin(Name, Password);
    return admin;
}

//Initializes data, allow user to select a usertype and login or register, if user exits, data is saved
void main()
{
    init_Data();
    while (true)
    {
        string Account = AccountType();

        if (Account == "1") {
            cout << redundantBuffer << endl;
            cout << "1) Login\n2) Register\n3) Go back" << endl;
            cout << redundantBuffer << endl;
            string option;
            cin >> option;
            cinClear();

            if (option == "1")
            {
                Customer* customer = loginAccount();
                if (customer->name == "")
                {
                    cout << redundantBuffer << endl;
                    cout << "User cannot be found" << endl;
                    cout << redundantBuffer << endl;
                }
                else
                {
                    customerMenu(customer);
                }

            }
            else if (option == "2")
            {
                createAccount();
            }
            else if (option == "3") {}
            else
            {
                cout << redundantBuffer << endl;
                cout << "Enter a valid option" << endl;
                cout << redundantBuffer << endl;
            }
        }

        else if (Account == "2") {

            Admin admin = adminLogin();

            if (admin.name == "") {
                cout << redundantBuffer << endl;
                cout << "Admin cannot be found" << endl;
                cout << redundantBuffer << endl;
            }
            else {
                while (true) {
                    cout << redundantBuffer << endl;
                    cout << "1) View Orders\n2) Logout" << endl;
                    cout << redundantBuffer << endl;
                    string option;
                    cin >> option;
                    cinClear();

                    if (option == "1") {
                        printAdminOrders(admin);
                        string adminOption = AdminMenu();

                        if (adminOption == "1") {

                        }
                    }
                    else if (option == "2") {
                        cout << redundantBuffer << endl;
                        cout << "Logged Out" << endl;
                        cout << redundantBuffer << endl;
                        break;
                    }
                    else {
                        cout << redundantBuffer << endl;
                        cout << "Enter a valid option" << endl;
                        cout << redundantBuffer << endl;
                    }
                }
            }

        }

        else if (Account == "3")
        {
            cout << "Exiting Program" << endl;
            update_Data();
            exit(0);
        }
    }
}

