// MakingOrder.h
// MakingOrder class definition.
#ifndef MAKING_ORDER_H
#define MAKING_ORDER_H

#include "AccountDatabase.h" // AccountDatabase class definition
#include "OrderDatabase.h" // OrderDatabase class definition

class MakingOrder
{
public:
   // constructor initializes data members
   MakingOrder( string theEmail, AccountDatabase &theAccountDatabase, OrderDatabase &theOrderDatabase );
   void run(); // start the MakingOrder
   void checkout(); // creates an order, and push it into orderDatabase
private:
   string email; // used as the account number
   Account currentAccount; // current account
   AccountDatabase &accountDatabase; // account database
   OrderDatabase &orderDatabase; // order database

   int enterChoice(); // let user choose: 1. Continue Shopping, 2. Proceed to Checkout or 3. Abandon
}; // end class MakingOrder

#endif // MAKING_ORDER_H