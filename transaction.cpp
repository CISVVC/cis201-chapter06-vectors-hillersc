/*
File: transaction.cpp
Description: Implementation for Transaction class
Author: Colby Hillers
Email: hillersc144964@student.vvc.edu
Date: 11/15/18
*/

#include "transaction.h"
#include <iostream>

// Initialize all values to 0
Transaction::Transaction()
{
    newDay = 0;
    newAmount = 0.0;
}

// Initialize values to parameters, respectively
Transaction::Transaction(int day, double amount, std::string description)
{
    newDay = day;
    newAmount = amount;
    newDescription = description;
}

// Prompt user to enter values for Transaction object
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

// Simply print all the values in a Transaction object
void Transaction::print() const
{
    std::cout << "Day: " << newDay << std::endl;
    std::cout << "Amount: " << newAmount << std::endl;
    std::cout << "Description: " << newDescription << std::endl;
}

// Self explanatory...
int Transaction::get_day() const
{
    return newDay;
}

// Self explanatory...
double Transaction::get_amount() const
{
    return newAmount;
}

// Self explanatory...
std::string Transaction::get_description() const
{
    return newDescription;
}
