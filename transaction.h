#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <vector>

class Transaction
{
public:
    Transaction();
    Transaction(int day, double amount, std::string description);
    void read();
    void print() const; 
    int get_day() const;
    double get_amount() const;
    std::string get_description() const;
private:
    int newDay;
    double newAmount;
    std::string newDescription;
};

#endif
