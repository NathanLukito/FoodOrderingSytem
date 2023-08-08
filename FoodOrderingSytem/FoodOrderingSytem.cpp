#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
#include "List.h" 
#include "LinkedList.h"
#include "Restaurant.h"
#include "FoodItem.h"
#include <fstream>
using namespace std;

Dictionary Customers = Dictionary();
List<Order> Orders;
List<OrderItem> OrderItems;
List<FoodItem> FoodItems;
LinkedList Restaurants;

void init_Data()
{
    /*Restaurant Restaurant1("McDonalds", "Number 1 fast-food restaurant");
    Restaurant1.addFoodItem("McSpicy", "Spiciest burger", 7.90);
    Restaurant1.addFoodItem("Filet-o-fish", "Fishy burger", 5.60);
    Restaurant1.addFoodItem("McChicken", "Chicken burger", 5.00);
    Restaurants.addRestaurant(Restaurant1);
    Restaurant Restaurant2("Saizeriya", "Italian restaurant");
    Restaurant2.addFoodItem("Milano Doria", "Cheese rice with minced meat", 5.90);
    Restaurant2.addFoodItem("Milaono Gratin", "Cheese spaghetti with minced meat", 5.90);
    Restaurant2.addFoodItem("Carbonara Pasta", "Bacon spaghetti", 5.90);
    Restaurants.addRestaurant(Restaurant2);
    Restaurant Restaurant3("XiMenJie", "Taiwan food");
    Restaurant3.addFoodItem("Braised Pork Rice", "Pork rice with ginger,garlic and soy sauce", 9.40);
    Restaurant3.addFoodItem("Crispy chicken cube", "Chicken", 8.00);
    Restaurant3.addFoodItem("Crispy Chicken cutlet", "Rice with chicken cutlet", 10.40);
    Restaurants.addRestaurant(Restaurant3);*/

    Customers.insert("Nathan", Customer("Nathan", 12345678, "56347891"));
    Customers.insert("Marcello", Customer("Marcello", 22375453, "56335863"));
    Customers.insert("Fionntan", Customer("Fionntan", 57890457, "50577898"));
    Customers.insert("Julia", Customer("Julia", 20396008, "56245395"));
    Customers.insert("Lucian", Customer("Lucian", 80398454, "45689297"));

    Orders.add(Order(1, "0", "Nathan"));
    Orders.add(Order(2, "0", "Marcello"));
    Orders.add(Order(3, "0", "Fionntan"));
    Orders.add(Order(4, "0", "Julia"));
    Orders.add(Order(5, "0", "Lucian"));

    OrderItems.add(OrderItem("Foodname", 1, 1));
    OrderItems.add(OrderItem("Foodname", 1, 1));
    OrderItems.add(OrderItem("Foodname", 1, 1));
    OrderItems.add(OrderItem("Foodname", 1, 2));
    OrderItems.add(OrderItem("Foodname", 1, 2));
    OrderItems.add(OrderItem("Foodname", 1, 2));
    OrderItems.add(OrderItem("Foodname", 1, 3));
    OrderItems.add(OrderItem("Foodname", 1, 3));
    OrderItems.add(OrderItem("Foodname", 1, 3));
    OrderItems.add(OrderItem("Foodname", 1, 4));
    OrderItems.add(OrderItem("Foodname", 1, 4));
    OrderItems.add(OrderItem("Foodname", 1, 4));
    OrderItems.add(OrderItem("Foodname", 1, 5));
    OrderItems.add(OrderItem("Foodname", 1, 5));
    OrderItems.add(OrderItem("Foodname", 1, 5));

    FoodItems.add(FoodItem("Foodname", "Description", "Category", 10.00));

}

string* splitString(string str)
{
    string arr[2] = {};
    int count = 0;
    for (int i = 0; i > str.size();i++)
    {
        if (!isspace(str[i]))
        {
            if (str[i] != (char)",")
            {
                arr[count] = arr[count] + str[i];
            }
            else
            {
                count++;
            }
            
        }
    }
    return arr;
}

Order getOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.customerName == customer->name)
            {
                return firstNode->item;
            }
            firstNode = firstNode->next;
        }
    }
    else
    {
        cout << "There are no Orders" << endl;
    }
}

int getOrderItemTotalPrice(OrderItem orderItem)
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
    }
    return totalPrice;
}

void printOrder(Order order)
{
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == order.OrderID)
            {
                cout << firstNode->item.name << " | x" << firstNode->item.quantity << "Price: $" << getOrderItemTotalPrice(firstNode->item) << endl;
            }
            firstNode = firstNode->next;
        }
    }
}



void removeOrderItem(string name, Customer* customer)
{
    Order order = getOrder(customer);
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    int index = 0;
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.name == name)
            {
                if (firstNode->item.quantity != 1)
                {
                    firstNode->item.quantity -= 1;
                }
                else
                {
                    OrderItems.remove(index);
                }
            }
            index++;
            firstNode = firstNode->next;
        }
    }
}

void clearOrder(Customer* customer)
{
    Order order = getOrder(customer);
    order.orderStatus = "0";
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    int index = 0;
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == order.OrderID)
            {
                OrderItems.remove(index);      
            }
            index++;
            firstNode = firstNode->next;
        }
    }
}

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
    Customers.insert(Name, Customer(Name, Password, telPhoneNum));
}

string printMainMenu()
{
    cout << "1) Login\n2) Register\n3) Exit" << endl;
    string option;
    cin >> option;
    cin.clear();
    cin.ignore(10000, '\n');
    return option;
}

void removeItemMenu(Customer* customer)
{
    while (true)
    {
        printOrder(getOrder(customer));
        cout << "Type the name of the item then the quantity you want removed" << endl;
        string name;
        getline(cin, name);
        cin.clear();
        cin.ignore(10000, '\n');
        removeOrderItem(name, customer);
    }
}

void addItemMenu(Customer* customer)
{
    List<FoodItem*> foodItems = {};
    Restaurant restaurant = Restaurant();
    FoodItem foodItem = FoodItem();
    while (true)
    {
        string searchOption;
        Restaurants.print();
        cout << "1) Search restaurant\n2) Search food name\n3) Search Category\n4) Cancel" << endl;
        cin >> searchOption;
        cin.clear();
        cin.ignore(10000, '\n');
        if (searchOption == "3")
        {
            //Restaurants.dynamicSearch(searchOption, searchOption, &foodItems, &restaurant, &foodItem);
            restaurant.displayMenu();
        }
    }
}

void orderMenu(Customer* customer)
{
    string orderOption;
    string menuArray[2] = { "1) Go back\n2) Add Items\n3) Cancel Order\n4) Send Order", "1) Go back\n2) Remove Items\n3) Add Items\n4) Cancel Order\n5) Send Order" };
    while (true)
    {
        string orderStatus = getOrder(customer).orderStatus;
        if (orderStatus == "0")
        {
            cout << menuArray[0] << endl;
            cin >> orderOption;
            cin.clear();
            cin.ignore(10000, '\n');
            if (orderOption == "1")
            {
                return;
            }
            else if (orderOption == "2")
            {
                addItemMenu(customer);
            }
            else if (orderOption == "3")
            {
                //Empty out order, reset orderStatus to 0
                clearOrder(customer);
                cout << "Order Cancelled" << endl;
            }
            else if (orderOption == "4")
            {
                //Send order function
            }
        }
        else if (orderStatus == "1")
        {
            cout << menuArray[1] << endl;
            cin >> orderOption;
            cin.clear();
            cin.ignore(10000, '\n');
            if (orderOption == "1")
            {
                return;
            }
            else if (orderOption == "2")
            {
                removeItemMenu(customer);
            }
            else if (orderOption == "3")
            {
                addItemMenu(customer);
            }
            else if (orderOption == "4")
            {
                //Empty out order, reset orderStatus to 0
                clearOrder(customer);
                cout << "Order Cancelled" << endl;
            }
            else if (orderOption == "5")
            {
                //send order function
            }
            return;
        }
    }
}




int customerMenu(Customer* customer)
{
    while (true)
    {
        cout << "1) Browse Restaurants\n2) View Order\n3) Logout" << endl;;
        string accountOption;
        cin >> accountOption;
        cin.clear();
        cin.ignore(10000, '\n');
        if (accountOption == "1")
        {
            return 0;
        }
        else if (accountOption == "2")
        {
            printOrder(getOrder(customer));
            orderMenu(customer);
        }
        else if (accountOption == "3")
        {
            cout << "Logged Out" << endl;
            return 0;
        }
        else
        {
            cout << "Enter a valid option" << endl;
        }
    }
    return 0;
}


void main()
{
    init_Data();
    while (true)
    {
        string option = printMainMenu();

        if (option == "1")
        {
            Customer* customer = loginAccount();
            if (customer->name == "")
            {
                cout << "User cannot be found" << endl;
            }
            else
            {
                int accountOption = customerMenu(customer);
            }
            
        }
        else if (option == "2")
        {
            createAccount();
        }
        else if (option == "3")
        {
            cout << "Exiting Program" << endl;
            exit(0);
        }
        else
        {
            cout << "Enter a valid option" << endl;
        }
    }
}
