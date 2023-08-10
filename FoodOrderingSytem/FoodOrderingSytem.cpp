#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
#include "List.h" 
#include "LinkedList.h"
#include "Restaurant.h"
#include "FoodItem.h"
#include "Admin.h"
#include <iomanip>

#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Dictionary Customers = Dictionary();
List<Order> Orders;
List<OrderItem> OrderItems;
List<FoodItem> FoodItems;
List<Admin> Admins;

string redundantBuffer = "\n\n_______________________________________________________________________________________________\n\n";
void cinClear()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

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
        getline(ss, name, ',');
        if (name == "")
        {
            break;
        }
        getline(ss, password, ',');
        getline(ss, telPhoneNumber, ',');
        Customers.insert(name, Customer(name, stoi(password), telPhoneNumber));
    }
    File.close();
}

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
        getline(ss, OrderID, ',');
        if (OrderID == "")
        {
            break;
        }
        getline(ss, orderStatus, ',');
        getline(ss, customerName, ',');
        Orders.add(Order(stoi(OrderID), orderStatus, customerName));
    }
    File.close();
}

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

void init_Data()
{
   /*
    for (int store = 0; store < Admins.getLength(); store++)
    {
        List<Admin>::Node<Admin>* storeNode = Admins.get(store);
        for (int fooditem = 0; fooditem < FoodItems.getLength(); fooditem++) {
            List<FoodItem>::Node<FoodItem>* foodItemNode = FoodItems.get(fooditem);
            if (storeNode->item.name == foodItemNode->item.foodItemName) {
                storeNode->item.addFoodItem(foodItemNode->item);
            }
        }
    }*/

    init_customers();
    init_orders();
    init_orderItems();
    init_admins();
    init_fooditems();
}

void update_customers()
{
    Customers.UpdateCustomer();
}

void update_orders()
{

}

void update_orderItems()
{

}

void update_admins()
{

}

void update_fooditems()
{

}

void update_Data()
{
    update_customers();
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
        totalPrice += firstNode->item.price;
    }
    return totalPrice*orderItem.quantity;
}

void printOrder(Order order)
{
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    bool check = false;
    double totalPrice;
    cout << redundantBuffer << endl;
    if (firstNode != nullptr && order.orderStatus != "0")
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.OrderID == order.OrderID)
            {
                check = true;
                double orderItemPrice = getOrderItemPrice(firstNode->item);
                totalPrice = orderItemPrice;
                cout << firstNode->item.name << " | x" << firstNode->item.quantity << " | Price: $" << orderItemPrice << endl;
            }
            firstNode = firstNode->next;
        }
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
            if (firstNode->item.name == name && firstNode->item.OrderID == order.OrderID)
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
    Customers.insert(Name, Customer(Name, Password, telPhoneNum));
    
    Orders.add(Order(Orders.size + 1, "0", Name));
}

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

void printFoodItems()
{
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            firstNode->item.print();
            firstNode = firstNode->next;
        }
    }
}

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

List<string>* printCategories()
{
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    List<string> Categories;
    if (firstNode != nullptr)
    {
        cout << redundantBuffer << "Categories" << redundantBuffer<< endl;
        while (firstNode->next != nullptr)
        {
            if (!isDuplicate(Categories, firstNode->item.category))
            {
                cout << "[ " << firstNode->item.category << " ]" << endl;
                Categories.add(firstNode->item.category);
            }
            firstNode = firstNode->next;
        }
    }
    return &Categories;
}

void printFoodfromCat(string category)
{
    List<FoodItem>::Node<FoodItem>* firstNode = FoodItems.get(0);
    if (firstNode != nullptr)
    {
        cout << redundantBuffer << endl;
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.category == category)
            {
                firstNode->item.print();
            }
            firstNode = firstNode->next;
        }
        cout << redundantBuffer << endl;
    }
}

bool addOrderItemDuplicate(string foodName)
{
    List<OrderItem>::Node<OrderItem>* firstNode = OrderItems.get(0);
    while (firstNode->next != nullptr)
    {
        if (firstNode->item.name == foodName)
        {
            firstNode->item.quantity++;
            return true;
        }
    }
    return false;
}

void addItemMenu(Customer* customer, string categoryOption)
{
    while (true)
    {
        bool check = false;
        printFoodfromCat(categoryOption);
        cout << "Type the name of the food you want or type 'exit' to exit" << endl;
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
                if (firstNode->item.foodItemName == foodChoice)
                {
                    check = true;
                    if (!addOrderItemDuplicate(foodChoice))
                    {
                        OrderItems.add(OrderItem(foodChoice, 1, getOrder(customer).OrderID));
                    }
                }
                firstNode = firstNode->next;
            }
            if (!check)
            {
                cout << "Food not found" << endl;
            }
        }
    }
}

void chooseCategory(Customer* customer)
{
    printCategories();
    cout << redundantBuffer << "Type the name of the category you want to choose" << redundantBuffer << endl;
    string categoryOption;
    cin >> categoryOption;
    cinClear();
    addItemMenu(customer, categoryOption);
}

void searchItemMenu(Customer* customer)
{
    while (true)
    {
        string searchOption;
        cout << "display restaurant" << endl;
        cout << "1) Search restaurant\n2) Search food name\n3) Search Category\n4) Cancel" << endl;
        cin >> searchOption;
        cinClear();
        if (searchOption == "1")
        {
            //Restaurant search
        }
        else if (searchOption == "2")
        {
            printFoodItems();
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

void sendOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.customerName == customer->name)
            {
                firstNode->item.orderStatus = "2";
            }
            firstNode = firstNode->next;
        }
    }
    cout << redundantBuffer << endl;
    cout << "Order sent, currently preparing order... ... " << endl;
    cout << redundantBuffer << endl;
}

void cancelOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.customerName == customer->name)
            {
                firstNode->item.orderStatus = "1";
            }
            firstNode = firstNode->next;
        }
    }
    cout << redundantBuffer << endl;
    cout << "Order Cancelled" << endl;
    cout << redundantBuffer << endl;
}

void acceptOrderMessage()
{
    cout << redundantBuffer << endl;
    cout << "Your food has been prepared, please collect your food" << endl;
    cout << "Once you have collected the food, accept the order on the system" << endl;
    cout << redundantBuffer << endl;
}

void acceptOrder(Customer* customer)
{
    List<Order>::Node<Order>* firstNode = Orders.get(0);
    if (firstNode != nullptr)
    {
        while (firstNode->next != nullptr)
        {
            if (firstNode->item.customerName == customer->name)
            {
                firstNode->item.orderStatus = "0";
            }
            firstNode = firstNode->next;
        }
    }
    clearOrder(customer);
    cout << redundantBuffer << endl;
    cout << "Order Accepted" << endl;
    cout << redundantBuffer << endl;
}

void orderMenu(Customer* customer)
{
    string orderOption;
    string menuArray[5] = { "1) Go back\n2) Add Items", "1) Go back\n2) Remove Items\n3) Add Items\n4) Clear Order\n5) Send Order", "1) Go back\n2) Cancel Order", "1) Go back\n2) Accept Order", "1) Go back\n2) Resolved"};
    while (true)
    {
        string orderStatus = getOrder(customer).orderStatus; // error here problem due to last person in list
        if (orderStatus == "0")
        {
            cout << menuArray[0] << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if (orderOption == "2")
            {
                printOrder(getOrder(customer));
                searchItemMenu(customer);
                printOrder(getOrder(customer));
            }
        }
        else if (orderStatus == "1")
        {
            cout << menuArray[1] << endl;
            cin >> orderOption;
            cinClear();
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
                searchItemMenu(customer);
                printOrder(getOrder(customer));
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
                printOrder(getOrder(customer));
            }
            return;
        }
        else if(orderStatus == "2")
        {
            cout << menuArray[2] << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if(orderOption == "2")
            {
                printOrder(getOrder(customer));
                cancelOrder(customer);
                printOrder(getOrder(customer));
            }
        }
        else if (orderStatus == "3")
        {
            cout << menuArray[3] << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if (orderOption == "2")
            {
                printOrder(getOrder(customer));
                acceptOrderMessage();
                acceptOrder(customer);
            }
        }
        else if (orderStatus == "4")
        {
            cout << menuArray[4];
            cout << "Your order has been cancelled by the restaurant, go to the restaurant to find out more" << endl;
            cin >> orderOption;
            cinClear();
            if (orderOption == "1")
            {
                return;
            }
            else if(orderOption == "2")
            {
                clearOrder(customer);
            }
            printOrder(getOrder(customer));
            
        }
    }
}

void customerMenu(Customer* customer)
{
    while (true)
    {
        cout << "1) Search for food\n2) View Order\n3) Logout" << endl;;
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
            cout << "Logged Out" << endl;
            return;
        }
        else
        {
            cout << "Enter a valid option" << endl;
        }
    }
    return;
}

void main()
{
    init_Data();
    /*
    for (int store = 0; store < Admins.getLength(); store++) {
        List<Admin>::Node<Admin>* storeNode = Admins.get(store);
        printStore(storeNode->item);
    }*/
    while (true)
    {
        cout << "1) Login\n2) Register\n3) Exit" << endl;
        string option;
        cin >> option;
        cinClear();

        if (option == "1")
        {
            Customer* customer = loginAccount();
            if (customer->name == "")
            {
                cout << "User cannot be found" << endl;
            }
            else
            {
                customerMenu(customer);
            }
            
        }
        else if (option == "2")
        {
            createAccount();
            init_Data();
        }
        else if (option == "3")
        {
            cout << "Exiting Program" << endl;
            update_Data();
            exit(0);
        }
        else
        {
            cout << "Enter a valid option" << endl;
        }
    }
}
