// OrderHistory.h
// OrderHistory class definition.
#ifndef ORDER_HISTORY_H
#define ORDER_HISTORY_H

#include "AccountDatabase.h" // AccountDatabase class definition
#include "OrderDatabase.h" // OrderDatabase class definition

class OrderHistory
{
public:
   // constructor initializes data members
   OrderHistory( string, AccountDatabase &, OrderDatabase & );
   void run(); // start the OrderHistory
private:
   string email; // used as the account number
   AccountDatabase &accountDatabase; // account database
   OrderDatabase &orderDatabase; // order database
}; // end class OrderHistory

#endif // ORDER_HISTORY_H