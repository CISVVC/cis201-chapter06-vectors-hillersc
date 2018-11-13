#include "transaction.h"
#include "transactionlog.h"
#include <iostream>

int main()
{
    Transactionlog statement;

    statement.read();
    statement.print_vector();

    return 0;
}
