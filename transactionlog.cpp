#include "transactionlog.h"
#include "transaction.h"
#include <string>
#include <vector>
#include <iostream>

// Initialize default constructor values to zero
Transactionlog::Transactionlog()
{
    newAmount = 0.0;
    newMinBal = 0.0;
    newAvgBal = 0.0;
}    

// Constant loop asking user to input Transaction objects into vector
void Transactionlog::read()
{
    while(true)
    {
        Transaction t;
        t.read();
        // Put newest Transaction object in back of vector
        newTransactions.push_back(t);
        std::cout << "Enter another (Y/N) ";
        char resp;
        std::cin >> resp;
        if(resp != 'Y' && resp != 'y')
            break;
    }

    amount(newTransactions);
}

// Find amount/balance of a Transaction within vector t
void Transactionlog::amount(std::vector<Transaction> &t)
{
    newAmount = 0.0;
    for(int i = 0; i < t.size(); i++)
    {
        newAmount += t[i].get_amount();
        dailyBalance.push_back(newAmount);
    }
}
// Print vector containing all Transactions
void Transactionlog::print_vector()
{
    // Loop through each Transaction and give it's data this display
    for(int i = 0; i < newTransactions.size(); i++)
    {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Day: " << newTransactions[i].get_day() << std::endl;
        std::cout << "Transaction: " << newTransactions[i].get_amount() << std::endl;
        std::cout << "Description: " << newTransactions[i].get_descrip() << std::endl;
        std::cout << "Daily Balance: " << dailyBalance[i] << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
    // Display the minimum balance and minimum balance with interest
    std::cout << "Minimum Balance: " << min_daily_bal(dailyBalance) << std::endl;
    std::cout << "Interest on Minimum: " << min_daily_bal(dailyBalance) * .005 
        << std::endl;
    // Display the average balance and the average balance with interest
    std::cout << "Average Balance: " << avg_daily_bal(dailyBalance) << std::endl;
    std::cout << "Interest on Average: " << avg_daily_bal(dailyBalance) * .005 
        << std::endl;
}

// Return the minimum daily balance
double Transactionlog::min_daily_bal(const std::vector<double> &t)
{
    double newMinBal = t[0];
    // Loop through reference vector and find lowest value
    for(int i = 0; i < t.size(); i++)
    {
        if(t[i] < newMinBal)
            newMinBal = t[i];
    }
    return newMinBal;
}

double Transactionlog::avg_daily_bal(const std::vector<double> &t)
{
    double sum = 0.0;
    // Loop reference vector and add up all the balances
    for(int i = 0; i < t.size(); i++)
    {
        sum += t[i];
    }
    // Take average of balances by dividing amount of balances
    return sum / t.size();
}
