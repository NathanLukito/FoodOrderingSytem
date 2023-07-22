#include <iostream>
#include "Customer.h"
#include "Dictionary.h"
using namespace std;


Dictionary init_Data()
{
    Dictionary Users = Dictionary();
    Users.insert("Nathan", Customer(string("Nathan"), 60398455, string("56347891"), Order()));
    Users.insert("Marcello", Customer(string("Marcello"), 22375453, string("56335863"), Order()));
    Users.insert("Fionntan", Customer(string("Fionntan"), 57890457, string("50577898"), Order()));
    Users.insert("Julia", Customer(string("Julia"), 20396008, string("56245395"), Order()));
    Users.insert("Lucian", Customer(string("Lucian"), 80398454, string("45689297"), Order()));
    return Users;
}

int main()
{
    Dictionary Users = init_Data();
    Users.print();
    return 0;
}
