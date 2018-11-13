#include "transactionlog.h"
#include "transaction.h"
#include <string>
#include <vector>
#include <iostream>

Transactionlog::Transactionlog()
{
    
}

void Transactionlog::read()
{
    while(true)
    {
        Transaction t;
        t.read();
        newTransactions.push_back(t);
        std::cout << "Enter another (Y/N) ";
        char resp;
        std::cin >> resp;
        if(resp != 'Y' && resp != 'y')
            break;
    }

    amount(newTransactions);
}

void Transactionlog::amount(std::vector<Transaction> &t)
{
    newAmount = 0.0;
    int size = t.size();
    for(int i = 0; i < size; i++)
    {
        newAmount += t[i].get_amount();
        dailyBalance.push_back(newAmount);
    }
}

void Transactionlog::print_vector()
{
    int size = newTransactions.size();
    for(int i = 0; i < size; i++)
    {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Day: " << newTransactions[i].get_day() << std::endl;
        std::cout << "Transaction: " << newTransactions[i].get_amount() << std::endl;
        std::cout << "Description: " << newTransactions[i].get_descrip() << std::endl;
        std::cout << "Daily Balance: " << dailyBalance[i] << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
    std::cout << "Minimum Balance: " << min_daily_bal(dailyBalance) << std::endl;
    std::cout << "Interest on Minimum: " << min_daily_bal(dailyBalance) * INTEREST << std::endl;
    std::cout << "Average Balance: " << avg_daily_bal(dailyBalance) << std::endl;
    std::cout << "Interest on Average: " << avg_daily_bal(dailyBalance) * INTEREST << std::endl;
}

double Transactionlog::min_daily_bal(const std::vector<double> &t)
{
    double newMinBal = t[0];
    int size = t.size();
    for(int i = 0; i < size; i++)
    {
        if(t[i] < newMinBal)
            newMinBal = t[i];
    }

    return newMinBal;
}

double Transactionlog::avg_daily_bal(const std::vector<double> &t)
{
    double sum = 0.0;
    int size = t.size();
    for(int i = 0; i < size; i++)
    {
        sum += t[i];
    }

    return sum / size;
}

