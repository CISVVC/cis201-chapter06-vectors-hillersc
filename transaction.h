#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <vector>

class Transaction
{
public:
    Transaction();
    Transaction(int day, double amount, std::string descrip);
    void read();
    int get_day();
    double get_amount();
    std::string get_descrip();
private:
    int newDay;
    double newAmount;
    std::string newDescrip;
};

#endif
