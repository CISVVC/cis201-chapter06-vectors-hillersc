#include "statement.h"
#include "transaction.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

const int MAX_DAY = 30;
const double INTEREST = .005;

void Statement::add_transaction(const Transaction &t)
{
    newTransactions.push_back(t);
}

std::vector<Transaction> Statement::get_transactions_for_day(int day) const
{
    std::vector<Transaction> transactionsForDay;
    for(int i = 0; i < newTransactions.size(); i++)
    {
        if(newTransactions[i].get_day() == day)
            transactionsForDay.push_back(newTransactions[i]);
    }
    return transactionsForDay;
}
std::vector<double> Statement::get_daily_balances() const
{
    std::vector<double> dailyBalances;
    double balance = 0.0;
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
    for(int i = 0; i < balances.size(); i++)
    {
        avgDailyBalance += balances[i];
    }
    return static_cast<double>(avgDailyBalance / balances.size());
}

double Statement::get_min_daily_balance(const std::vector<double> &balances) const
{
    double minDailyBalance = balances[0];
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
    for(int i = 0; i < newTransactions.size(); i++)
    {
        if(newTransactions[i].get_day() == day)
            totalForDay += newTransactions[i].get_amount();
    }
    return totalForDay;
}

void Statement::print_transactions_for_day(int day) const
{
    for(int i = 0; i < newTransactions.size(); i++)
    {
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
    for(int day = 0; day < MAX_DAY; day++)
    {
        print_transactions_for_day(day+1);
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Balance for day " << day + 1 << " is: " << balances[day] << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
    std::cout << "Average Daily Balance: " << get_avg_daily_balance(get_daily_balances()) << std::endl;
    std::cout << "Minimum Daily Balance: " << get_min_daily_balance(get_daily_balances()) << std::endl;
    print_interest();
}

void Statement::print_interest() const
{
    std::cout << "Interest on Average: " << std::setprecision(3) << get_avg_daily_balance(get_daily_balances()) * INTEREST
        << std::endl;
    std::cout << "Interest on Minimum: " << std::setprecision(3) << get_min_daily_balance(get_daily_balances()) * INTEREST
        << std::endl;
}
