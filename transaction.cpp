#include "transaction.h"
#include <iostream>

// Initialize default constructor values to zero
Transaction::Transaction()
{
    newDay = 0;
    newAmount = 0.0;
}

// Initialize object's values to user's parameters
Transaction::Transaction(int day, double amount, std::string descrip)
{
    newDay = day;
    newAmount = amount;
    newDescrip = descrip;
}

// Read in user values to put in Transaction object
void Transaction::read()
{
    std::cout << "Day: ";
    std::cin >> newDay;
    std::cout << "Amount: ";
    std::cin >> newAmount;
    std::cin.ignore();
    std::cout << "Description: ";
    std::getline(std::cin, newDescrip);
}

// Return day as an int
int Transaction::get_day()
{
    return newDay;
}

// Return amount/balance as double
double Transaction::get_amount()
{
    return newAmount;
}

// Return description as a string
std::string Transaction::get_descrip()
{
    return newDescrip;
}
