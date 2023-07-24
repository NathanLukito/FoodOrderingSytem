#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
#include <typeinfo>
using namespace std;

Dictionary Users = Dictionary();

void init_Data()
{
    Users.insert("Nathan", Customer("Nathan", 12345678, "56347891", Order()));
    Users.insert("Marcello", Customer("Marcello", 22375453, "56335863", Order()));
    Users.insert("Fionntan", Customer("Fionntan", 57890457, "50577898", Order()));
    Users.insert("Julia", Customer("Julia", 20396008, "56245395", Order()));
    Users.insert("Lucian", Customer("Lucian", 80398454, "45689297", Order()));
}

User* loginAccount()
{
    cout << "Enter your name: " << endl;
    string Name;
    cin >> Name;
    cout << "Enter a password: " << endl;
    int Password;
    cin >> Password;
    return Users.findUser(Name, Password);
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

    Users.insert(Name, Customer(Name, Password, telPhoneNum, Order()));
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
            User* user = loginAccount();
            cout << typeid(user).name() << endl;
            Customer* customer = dynamic_cast<Customer*>(user);
            if (typeid(customer) == typeid(Customer*))
            { 
                customer->order.printOrder();
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
            else
            {
                cout << "Admin" << endl;
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
