#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <vector>

class Transaction
{
public:
    // Transaction constructors
    Transaction();
    Transaction(int day, double amount, std::string descrip);
    // Reads in values for Transaction object
    void read();
    // Return day for Transaction object
    int get_day();
    // Return amount/balance for Transaction object
    double get_amount();
    // Return description for Transaction object
    std::string get_descrip();
private:
    int newDay;
    double newAmount;
    std::string newDescrip;
};

#endif
