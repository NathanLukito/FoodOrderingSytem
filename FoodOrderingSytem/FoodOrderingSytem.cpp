#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
#include "List.h" 
#include "LinkedList.h"
#include "Restaurant.h"
#include "FoodItem.h"
#include "Admin.h"

#include <fstream>
using namespace std;

Dictionary Customers;
List<Order> Orders;
List<OrderItem> OrderItems;
List<FoodItem> FoodItems;
List<Admin> Admins;

void init_Data()
{
    Admins.add(Admin("McDonalds", "12345678", "Fast food restaurant", "Bukit Batok"));
    Admins.add(Admin("Saizeriya", "98765432", "Italian restaurant", "Bukit Panjang"));
    Admins.add(Admin("XiMenJie", "67543821", "Taiwan food", "Choa Chu Kang"));

    FoodItems.add(FoodItem("McSpicy", "Spiciest burger", "Burger", 7.90, "McDonalds"));
    FoodItems.add(FoodItem("Filet-o-fish", "Fishy burger", "Burger", 5.60, "McDonalds"));
    FoodItems.add(FoodItem("McChicken", "Chicken burger", "Burger", 5.00, "McDonalds"));
    FoodItems.add(FoodItem("Milano Doria", "Cheese rice with minced meat", "Italian", 5.90, "Saizeriya"));
    FoodItems.add(FoodItem("Milaono Gratin", "Cheese spaghetti with minced meat", "Italian", 5.90, "Saizeriya"));
    FoodItems.add(FoodItem("Carbonara Pasta", "Bacon spaghetti", "Pasta", 5.90, "Saizeriya"));
    FoodItems.add(FoodItem("Braised Pork Rice", "Pork rice with ginger,garlic and soy sauce", "Rice", 9.40, "XiMenJie"));
    FoodItems.add(FoodItem("Crispy chicken cube", "Chicken", "Rice", 8.00, "XiMenJie"));
    FoodItems.add(FoodItem("Crispy Chicken cutlet", "Rice with chicken cutlet", "Rice", 10.40, "XiMenJie"));

    for (int store = 0; store < Admins.getLength(); store++)
    {
        List<Admin>::Node<Admin>* storeNode = Admins.get(store);
        for (int fooditem = 0; fooditem < FoodItems.getLength(); fooditem++) {
            List<FoodItem>::Node<FoodItem>* foodItemNode = FoodItems.get(fooditem);
            if (storeNode->item.name == foodItemNode->item.foodItemName) {
                storeNode->item.addFoodItem(foodItemNode->item);
            }
        }
    }

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

    Orders.add(Order(1, "1", "Nathan"));
    Orders.add(Order(2, "1", "Marcello"));
    Orders.add(Order(3, "1", "Fionntan"));
    Orders.add(Order(4, "1", "Julia"));
    Orders.add(Order(5, "1", "Lucian"));

    OrderItems.add(OrderItem("Foodname", 3, 1));
    OrderItems.add(OrderItem("Foodname2", 3, 1));
    OrderItems.add(OrderItem("Foodname", 3, 2));
    OrderItems.add(OrderItem("Foodname", 3, 3));
    OrderItems.add(OrderItem("Foodname", 3, 4));
    OrderItems.add(OrderItem("Foodname", 3, 5));


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
        totalPrice += firstNode->item.price;
    }
    return totalPrice*orderItem.quantity;
}

void printOrder(Order order)
{
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    bool check = false;
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == order.OrderID)
            {
                check = true;
                cout << firstNode->item.name << " | x" << firstNode->item.quantity << " | Price: $" << getOrderItemTotalPrice(firstNode->item) << endl;
            }
            firstNode = firstNode->next;
        }
    }
    if (check == false)
    {
        cout << "There are no orderitems in your order" << endl;
    }
}

void printStore(Admin store) {
    cout << store.name << " " << store.description << endl;
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.adminName == store.name) {
                cout << firstNode->item.foodItemName << " " << firstNode->item.price << endl;
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
    List<Order>::Node<Order>* temp = Orders.get(0);
    Order* tempOrder = new Order;
    if (temp != nullptr)
    {
        while (temp->next != nullptr)
        {
            if (temp->item.customerName == customer->name)
            {
                temp->item.orderStatus = "0";
                tempOrder = &temp->item;
            }
            temp = temp->next;
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

Admin* findAdmin(string name, int password) {

}

Admin* adminLogin() {
    cout << "Enter your name: " << endl;
    string Name;
    cin >> Name;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter your password: " << endl;
    int Password;
    cin >> Password;
    cin.clear(10000, '\n');
    

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
    cout << "Type the name of the item you want removed" << endl;
    string name;
    cin >> name;
    cin.clear();
    cin.ignore(10000, '\n');
    removeOrderItem(name, customer);
    return;
}

void addItemMenu(Customer* customer)
{
    List<FoodItem*> foodItems = {};
    Restaurant restaurant = Restaurant();
    FoodItem foodItem = FoodItem();
    while (true)
    {
        string searchOption;
        //Restaurants.print();
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
    string menuArray[2] = { "1) Go back\n2) Add Items", "1) Go back\n2) Remove Items\n3) Add Items\n4) Cancel Order\n5) Send Order" };
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
                printOrder(getOrder(customer));
                addItemMenu(customer);
                printOrder(getOrder(customer));
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
                printOrder(getOrder(customer));
                removeItemMenu(customer);
                printOrder(getOrder(customer));
            }
            else if (orderOption == "3")
            {
                printOrder(getOrder(customer));
                addItemMenu(customer);
                printOrder(getOrder(customer));
            }
            else if (orderOption == "4")
            {
                //Empty out order, reset orderStatus to 0
                clearOrder(customer);
                cout << "Order Cancelled" << endl;
                return;
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

string AccountType() {
    cout << "1) Customer\n2) Admin\n3) Exit" << endl;
    string accountType;
    cin >> accountType;
    cin.clear();
    cin.ignore(10000, '\n');
    return accountType;
}

string AdminMenu() {
    cout << "";
}

void main()
{
    init_Data();
    while (true)
    {
        string accountType = AccountType();

        if (accountType == "1") {
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

        else if (accountType == "2") {
            cout << "";
        }
    }
}
