#include "transaction.h"
#include <iostream>

Transaction::Transaction()
{
    newDay = 0;
    newAmount = 0.0;
}

Transaction::Transaction(int day, double amount, std::string description)
{
    newDay = day;
    newAmount = amount;
    newDescription = description;
}

void Transaction::read()
{
    std::cout << "Day: ";
    std::cin >> newDay;
    std::cout << "Amount: ";
    std::cin >> newAmount;
    std::cin.ignore();
    std::cout << "Description: ";
    std::getline(std::cin, newDescription);
}

void Transaction::print() const
{
    std::cout << "Day: " << newDay << std::endl;
    std::cout << "Amount: " << newAmount << std::endl;
    std::cout << "Description: " << newDescription << std::endl;
}

int Transaction::get_day() const
{
    return newDay;
}

double Transaction::get_amount() const
{
    return newAmount;
}

std::string Transaction::get_description() const
{
    return newDescription;
}
