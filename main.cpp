#include "transaction.h"
#include "statement.h"
#include <iostream>

// Fill Statement object with Transaction objects
void add_transactions(Statement &s)
{
    s.add_transaction(Transaction(1, 1143.24, "Initial Balance"));
    s.add_transaction(Transaction(2, -224, "Check 2140"));
    s.add_transaction(Transaction(3, -193, "Check 2141"));
    s.add_transaction(Transaction(4, 500, "ATM deposit"));
    s.add_transaction(Transaction(5, -10, "Check 2142"));
    s.add_transaction(Transaction(6, -105, "Check 2143"));
    s.add_transaction(Transaction(7, -210, "Check 2144"));
    s.add_transaction(Transaction(8, -201, "Check 2145"));
    s.add_transaction(Transaction(16, 1200, "ATM deposit"));
    s.add_transaction(Transaction(16, -100, "Check 2146"));
    s.add_transaction(Transaction(17, -200, "Check 2147"));
    s.add_transaction(Transaction(20, 900, "ATM deposit"));
    s.add_transaction(Transaction(30, 700, "ATM deposit"));
    
}

int main()
{
    Statement balances;

    add_transactions(balances);

    // Output the statement of all entered Transactions
    balances.print_balances();
    
    return 0;
}
