/*
File: statement.cpp
Description: Implementation for Statement class
Author: Colby Hillers
Email: hillersc144964@student.vvc.edu
Date: 11/15/18
*/

#include "statement.h"
#include "transaction.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// const values allow for consistency throughout program
const int MAX_DAY = 30;
const double INTEREST = .005;

void Statement::add_transaction(const Transaction &t)
{
    // Pushes Transaction t to back of newTransactions
    newTransactions.push_back(t);
}

std::vector<Transaction> Statement::get_transactions_for_day(int day) const
{
    std::vector<Transaction> transactionsForDay;
    // Loops through newTransactions and test if each object shares the same day
    for(int i = 0; i < newTransactions.size(); i++)
    {
        // If object shares the same day, push to back of transactionsForDay
        if(newTransactions[i].get_day() == day)
            transactionsForDay.push_back(newTransactions[i]);
    }
    return transactionsForDay;
}
std::vector<double> Statement::get_daily_balances() const
{
    std::vector<double> dailyBalances;
    double balance = 0.0;
    // Loops through each day adding balances for each day to dailyBalances
    for(int day = 0; day < MAX_DAY; day++) 
    {
        balance += get_transaction_total_for_day(day+1);
        dailyBalances.push_back(balance);
    }
    return dailyBalances;
}

double Statement::get_avg_daily_balance(const std::vector<double> &balances) const
{
    double avgDailyBalance = 0.0;
    // Loops through balances vector and add each balance to avgDailyBalance
    for(int i = 0; i < balances.size(); i++)
    {
        avgDailyBalance += balances[i];
    }
    // Return the average
    return static_cast<double>(avgDailyBalance / balances.size());
}

double Statement::get_min_daily_balance(const std::vector<double> &balances) const
{
    double minDailyBalance = balances[0];
    // Loop through balances vector and test if each succesive value is lower than
    // minDailyBalance
    for(int i = 1; i < balances.size(); i++)
    {
        if(balances[i] < minDailyBalance)
            minDailyBalance = balances[i];
    }
    return minDailyBalance;
}

double Statement::get_transaction_total_for_day(int day) const
{
    double totalForDay = 0.0;
    // Loop through newTransactions and test if indexed object's day is equal to day
    for(int i = 0; i < newTransactions.size(); i++)
    {
        // If object shares same day than add its amount to totalForDay
        if(newTransactions[i].get_day() == day)
            totalForDay += newTransactions[i].get_amount();
    }
    return totalForDay;
}

void Statement::print_transactions_for_day(int day) const
{
    // Loop through newTransactions and test if indexed object shares specified day
    for(int i = 0; i < newTransactions.size(); i++)
    {
        // If object has the same day then run its print function
        if(newTransactions[i].get_day() == day)
            newTransactions[i].print();   
    }
}

void Statement::print_statement_header() const
{
    std::cout << "---------- Statement ----------" << std::endl;
}

void Statement::print_balances() const
{
    print_statement_header();

    std::vector<double> balances = get_daily_balances();
    // Loop through each day and run print_transactions_for_day for indexed day value
    for(int day = 0; day < MAX_DAY; day++)
    {
        print_transactions_for_day(day+1);
        // Formatting for outut
        std::cout << "-------------------------------" << std::endl;
        // Output balance for day at end of each day
        std::cout << "Balance for day " << day + 1 << " is: " << balances[day] << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
    // At the end of output, show Avg/Min balances w/ their interest earned
    std::cout << "Average Daily Balance: " << get_avg_daily_balance(get_daily_balances()) << std::endl;
    std::cout << "Minimum Daily Balance: " << get_min_daily_balance(get_daily_balances()) << std::endl;
    print_interest();
}

void Statement::print_interest() const
{
    // Multiply get_avg_daily_balance by INTEREST and set a precision of 3
    std::cout << "Interest on Average: " << std::setprecision(3) << get_avg_daily_balance(get_daily_balances()) * INTEREST
        << std::endl;
    // Multiply get_min_daily_balance by INTEREST and set a precision of 3
    std::cout << "Interest on Minimum: " << std::setprecision(3) << get_min_daily_balance(get_daily_balances()) * INTEREST
        << std::endl;
}
