#include "transaction.h"
#include "transactionlog.h"
#include <iostream>

int main()
{
	// Create Transactionlog object
    Transactionlog statement;

    // Read object
    statement.read();
    // Print the object's vector
    statement.print_vector();

    return 0;
}
