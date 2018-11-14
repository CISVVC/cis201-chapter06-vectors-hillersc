#ifndef TRANSACTIONLOG_H
#define TRANSACTIONLOG_H
#include "transaction.h"
#include <string>
#include <vector>

class Transactionlog
{
public:
    // Default constructor
    Transactionlog();
    // Read in Transaction objects
    void read();
    // Find amount in a vector of Transaction objects
    void amount(std::vector<Transaction> &t);
    // Print vector that contains all Transactions
    void print_vector();
    // Return the minimum daily balance of month
    double min_daily_bal(const std::vector<double> &t);
    // Return the average daily balance of the month
    double avg_daily_bal(const std::vector<double> &t);

private:
    std::vector<Transaction> newTransactions;
    std::vector<double> dailyBalance;
    double newAmount;
    double newMinBal;
    double newAvgBal;

};

#endif
