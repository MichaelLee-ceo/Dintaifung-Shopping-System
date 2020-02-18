#include <iostream>
#include <iomanip>
#include "Order.h" // Order class definition

extern const char foods[ 15 ][ 44 ];

Order::Order( string theOrderNumber, string theEmail )
{
   setOrderNumber( theOrderNumber );
   setEmail( theEmail );

   int quantity[ 15 ] = {};
   setOrderDetails( quantity );
}

void Order::setOrderNumber( string theOrderNumber )
{
   // copy at most 40 characters from theOrderNumber to orderNumber
   unsigned int length = theOrderNumber.size();
   length = ( length < 12 ? length : 11 );
   for( unsigned int i = 0; i < length; i++ )
      orderNumber[ i ] = theOrderNumber[ i ];
   orderNumber[ length ] = '\0';
}

string Order::getOrderNumber() const
{
   return orderNumber;
}

void Order::setEmail( string theEmail )
{
   // copy at most 40 characters from theEmail to email
   unsigned int length = theEmail.size();
   length = ( length < 40 ? length : 39 );
   for( unsigned int i = 0; i < length; i++ )
      email[ i ] = theEmail[ i ];
   email[ length ] = '\0';
}

// get email value
string Order::getEmail() const
{
   return email;
}

void Order::setOrderDetails( int theQuantity[] )
{
   if( theQuantity != 0 )
      for( int i = 0; i < 15; i++ )
         quantity[i] = ( theQuantity[i] >= 0 ? theQuantity[i] : 0 );
}

void Order::displayOrderDetails() const
{
   int total = 0;
   for( int i = 1; i < 15; i++ )
      if( quantity[ i ] > 0 )
      {
         cout << setw( 9 ) << i << setw( 44 ) << foods[ i ] << setw( 7 ) << price[ i ]
              << setw( 10 ) << quantity[ i ]
              << setw( 10 ) << price[ i ] * quantity[ i ] << endl;

         total += quantity[ i ] * price[ i ];
      }

   cout << "\nTotal: " << total << endl;
}