#ifndef TRANSACTIONLOG_H
#define TRANSACTIONLOG_H
#include "transaction.h"
#include <string>
#include <vector>

class Transactionlog
{
public:
    Transactionlog();
    void read();
    void amount(std::vector<Transaction> &t);
    void print_vector();
    double min_daily_bal(const std::vector<double> &t);
    double avg_daily_bal(const std::vector<double> &t);

private:
    std::vector<Transaction> newTransactions;
    std::vector<double> dailyBalance;
    double newAmount;
    double newMinBal;
    double newAvgBal;

};

#endif
