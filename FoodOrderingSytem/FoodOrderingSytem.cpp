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
