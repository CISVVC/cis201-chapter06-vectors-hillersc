#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <vector>

class Transaction
{
public:
    // Default constructor
    Transaction();
    // Normal constructor
    Transaction(int day, double amount, std::string description);
    // Read data in Transaction object
    void read();
    // Print data in Transaction object
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
