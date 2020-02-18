#include <iostream>
#include <iomanip>
#include "OrderHistory.h" // Member class definition

// Member constructor initializes attributes
OrderHistory::OrderHistory( string theEmail, AccountDatabase &theAccountDatabase, OrderDatabase &theOrderDatabase )
   : email( theEmail ),
     accountDatabase( theAccountDatabase ),
     orderDatabase( theOrderDatabase )
{
} // end Member constructor

void OrderHistory::run()
{

   if( !orderDatabase.existOrders( email ) )
   {
      cout << "\nYou have no order history!\n";
      return;
   }

   string name = accountDatabase.getName( email );

   orderDatabase.displayOrders( email, name );
}