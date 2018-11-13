#include "transaction.h"
#include <iostream>

Transaction::Transaction()
{
    newDay = 0;
    newAmount = 0.0;
}

Transaction::Transaction(int day, double amount, std::string descrip)
{
    newDay = day;
    newAmount = amount;
    newDescrip = descrip;
}

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

int Transaction::get_day()
{
    return newDay;
}

double Transaction::get_amount()
{
    return newAmount;
}

std::string Transaction::get_descrip()
{
    return newDescrip;
}
