#ifndef STATEMENT_H
#define STATEMENT_H
#include <vector>
#include "transaction.h"

class Statement
{
    // Vector contains all Transaction objects that user enters
    std::vector<Transaction> newTransactions;

public:
    // Add Transaction object to newTransactions
    void add_transaction(const Transaction &t);
    // Returns a vector of Transactions that have the same day
    std::vector<Transaction> get_transactions_for_day(int day) const;
    // Returns a vector of doubles of the balances for each day
    std::vector<double> get_daily_balances() const;
    // Takes average from "get_daily_balances" and returns it as double
    double get_avg_daily_balance(const std::vector<double> &balances) const;
    // Takes minimum from "get_daily_balances" and returns it as double
    double get_min_daily_balance(const std::vector<double> &balances) const;
    // Returns the total balance for a certain day
    double get_transaction_total_for_day(int day) const;
    // Prints all the Transactions for a specified day
    void print_transactions_for_day(int day) const;
    // Prints the header of the statement
    void print_statement_header() const;
    // Utilizes all print functions to print final output
    void print_balances() const;
    // Prints the interest earned on the average and minimum balances
    void print_interest() const;
};

#endif
