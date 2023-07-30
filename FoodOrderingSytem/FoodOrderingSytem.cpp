#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
#include "List.h" 
#include <typeinfo>
#include "Restaurant.h"
#include "FoodItem.h"

using namespace std;

Dictionary Customers = Dictionary();
LinkedList Restaurants;

void init_Data()
{
    Customers.insert("Nathan", Customer("Nathan", 12345678, "56347891", Order()));
    Customers.insert("Marcello", Customer("Marcello", 22375453, "56335863", Order()));
    Customers.insert("Fionntan", Customer("Fionntan", 57890457, "50577898", Order()));
    Customers.insert("Julia", Customer("Julia", 20396008, "56245395", Order()));
    Customers.insert("Lucian", Customer("Lucian", 80398454, "45689297", Order()));

    Restaurant Restaurant1("McDonalds", "Number 1 fast-food restaurant");
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
    Restaurants.addRestaurant(Restaurant3);
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
    Customers.insert(Name, Customer(Name, Password, telPhoneNum, Order()));
}

string printMenu()
{
    cout << "1) Login\n2) Register\n3) Exit" << endl;
    string option;
    cin >> option;
    cin.clear();
    cin.ignore(10000, '\n');
    return option;
}

int printCustomerMenu(Customer* customer)
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
            customer->order.printOrder();
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
        string option = printMenu();

        if (option == "1")
        {
            Customer* customer = loginAccount();
            if (customer->name == "")
            {
                cout << "User cannot be found" << endl;
            }
            else
            {
                int accountOption = printCustomerMenu(customer);
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
