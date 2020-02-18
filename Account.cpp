// Account.cpp
// Member-function definitions for class Account.
#include <iostream>
#include <iomanip>
#include "Account.h" // Account class definition

const int price[ 15 ] = { 0, 200, 144, 184, 176, 176, 396, 200,
                             200, 175, 175, 200, 225, 375, 350 };

// Account constructor initializes attributes
Account::Account( string theEmail, string thePassword, string theName, string theAddress, string thePhone )
{
   setEmail( theEmail );
   setPassword( thePassword );
   setName( theName );
   setAddress( theAddress );
   setPhone( thePhone );

   int cart[ 15 ] = {};
   setCart( cart );
} // end Account constructor

// determines whether a user-specified password matches password in Account
bool Account::validatePassword( string userPassword ) const
{ 
   return ( userPassword.compare( password ) == 0 );
} // end function validatePIN
   
// set email value
void Account::setEmail( string theEmail )
{
   // copy at most 40 characters from theEmail to email
   unsigned int length = theEmail.size();
   length = ( length < 40 ? length : 39 );
   for( unsigned int i = 0; i < length; i++ )
      email[ i ] = theEmail[ i ];
   email[ length ] = '\0';
}

// get email value
string Account::getEmail() const
{
   return email;
}

// set password value
void Account::setPassword( string thePassword )
{
   // copy at most 20 characters from thePassword to password
   unsigned int length = thePassword.size();
   length = ( length < 20 ? length : 19 );
   for( unsigned int i = 0; i < length; i++ )
      password[ i ] = thePassword[ i ];
   password[ length ] = '\0';
}

// get password value
string Account::getPassword() const
{
   return password;
}

// set name value
void Account::setName( string theName )
{
   // copy at most 8 characters from theName to name
   unsigned int length = theName.size();
   length = ( length < 8 ? length : 7 );
   for( unsigned int i = 0; i < length; i++ )
      name[ i ] = theName[ i ];
   name[ length ] = '\0';
}

// get name value
string Account::getName() const
{
   return name;
}

// set address value
void Account::setAddress( string theAddress )
{
   // copy at most 80 characters from theAddress to address
   unsigned int length = theAddress.size();
   length = ( length < 80 ? length : 79 );
   for( unsigned int i = 0; i < length; i++ )
      address[ i ] = theAddress[ i ];
   address[ length ] = '\0';
}

// get address value
string Account::getAddress() const
{
   return address;
}

// set phone value
void Account::setPhone( string thePhone )
{
   // copy at most 12 characters from thePhone to phone
   unsigned int length = thePhone.size();
   length = ( length < 12 ? length : 11 );
   for( unsigned int i = 0; i < length; i++ )
      phone[ i ] = thePhone[ i ];
   phone[ length ] = '\0';
}

// get phone value
string Account::getPhone() const
{
   return phone;
}

// set cart content
void Account::setCart( int *theCart )
{
   if( theCart != 0 )
      for( int i = 0; i < 15; i++ )
         cart[ i ] = ( theCart[ i ] >= 0 ? theCart[ i ] : 0 );
}

// set cart content
void Account::modifyCart( int code, int amount )
{
   if( code >= 0 && code <= 20 && amount >= 0 )
         cart[ code ] = amount;
}

// get pointer to cart
int * Account::getCart()
{
   return cart;
}

void Account::displayCart() const
{
   cout << "\nYour shopping cart:\n";
   cout << setw( 4 ) << "Code" << setw( 44 ) << "Item" << setw( 10 ) << "Quantity" << endl;

   for( int i = 1; i < 15; i++ )
      cout << setw( 4 ) << i << setw( 44 ) << foods[ i ] << setw( 10 ) << cart[ i ] << endl;
}

void Account::displayOrders() const
{
   int total = 0;
   for( int i = 0; i < 15; i++ )
      if( cart[ i ] > 0 )
      {
         cout << setw( 9 ) << i << setw( 44 ) << foods[ i ] << setw( 10 ) << price[ i ]
              << setw( 10 ) << cart[ i ]
              << setw( 10 ) << cart[ i ] * price[ i ] << endl;
         total += cart[ i ] * price[ i ];
      }

   cout << "\nTotal: " << total << endl;
}