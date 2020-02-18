// Account.h
// Account class definition.
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

extern const char foods[ 15 ][ 44 ];

class Account
{
public:
   // constructor sets attributes
   Account( string theEmail = "", string thePassword = "", string theName = "",
            string theAddress = "", string thePhone = "" );

   // determines whether a user-specified password matches password in Account
   bool validatePassword( string userPassword ) const;

   // accessor functions for email
   void setEmail( string theEmail );
   string getEmail() const;

   // accessor functions for password
   void setPassword( string thePassword );
   string getPassword() const;

   // accessor functions for name
   void setName( string theName );
   string getName() const;

   // accessor functions for address
   void setAddress( string theAddress );
   string getAddress() const;

   // accessor functions for phone
   void setPhone( string thePhone );
   string getPhone() const;

   // accessor functions for cart
   void setCart( int *theCart );
   int * getCart();

   void modifyCart( int code, int amount ); // cart[ code ] is modified to amount

   void displayCart() const; // Code, Item and Quantity of each foods in the shopping cart

   void displayOrders() const;
private:
   char email[ 40 ]; // used as the account number
   char password[ 20 ];
   char name[ 8 ];
   char address[ 80 ];
   char phone[ 12 ];
   int cart[ 15 ]; // cart[ i ] is the quantity of food #i in the shopping cart
}; // end class Account

#endif // ACCOUNT_H