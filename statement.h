#ifndef STATEMENT_H
#define STATEMENT_H
#include <vector>
#include "transaction.h"

class Statement
{
    std::vector<Transaction> newTransactions;

public:
    void add_transaction(const Transaction &t);
    std::vector<Transaction> get_transactions_for_day(int day) const;
    std::vector<double> get_daily_balances() const;
    double get_avg_daily_balance(const std::vector<double> &balances) const;
    double get_min_daily_balance(const std::vector<double> &balances) const;
    double get_transaction_total_for_day(int day) const;
    void print_transactions_for_day(int day) const;
    void print_statement_header() const;
    void print_balances() const;
    void print_interest() const;
};

#endif
