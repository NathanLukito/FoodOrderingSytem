#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
#include <typeinfo>
using namespace std;

Dictionary Customers = Dictionary();

void init_Data()
{
    Customers.insert("Nathan", Customer("Nathan", 12345678, "56347891", Order()));
    Customers.insert("Marcello", Customer("Marcello", 22375453, "56335863", Order()));
    Customers.insert("Fionntan", Customer("Fionntan", 57890457, "50577898", Order()));
    Customers.insert("Julia", Customer("Julia", 20396008, "56245395", Order()));
    Customers.insert("Lucian", Customer("Lucian", 80398454, "45689297", Order()));
}

Customer* loginAccount()
{
    cout << "Enter your name: " << endl;
    string Name;
    cin >> Name;
    cout << "Enter a password: " << endl;
    int Password;
    cin >> Password;
    return Customers.findCustomer(Name, Password);
}

void createAccount()
{
    cout << "Enter your name: " << endl;
    string Name;
    cin >> Name;
    cout << "Enter a password: " << endl;
    int Password;
    cin >> Password;
    cout << "Enter your phone number: " << endl;
    string telPhoneNum;
    cin >> telPhoneNum;

    Customers.insert(Name, Customer(Name, Password, telPhoneNum, Order()));
}

int printMenu()
{
    cout << "1) Login" << endl;
    cout << "2) Register" << endl;
    cout << "3) Exit" << endl;
    int option;
    cin >> option;
    return option;
}

int printCustomerMenu()
{
    cout << "1) Browse Restaurants" << endl;
    cout << "2) Track Current Order" << endl;
    cout << "3) Logout" << endl;
    int accountOption;
    cin >> accountOption;
    return accountOption;
}

void main()
{
    init_Data();
    while (true)
    {
        int option = printMenu();
        if (option == 1)
        {
            Customer* customer = loginAccount();
            int accountOption = printCustomerMenu();
            if (accountOption == 1)
            {
                exit(0);
            }
            else if (accountOption == 2)
            {
                customer->order.printOrder();
            }
            else if (accountOption == 3)
            {
                cout << "Logged Out" << endl;
            }
            else
            {
                cout << "Enter a valid option" << endl;
            }  
        }
        else if (option == 2)
        {
            createAccount();
        }
        else if (option == 3)
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
