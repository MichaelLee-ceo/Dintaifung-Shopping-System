// AccountDatabase.h
// AccountDatabase class definition.
#ifndef ACCOUNT_DATABASE_H
#define ACCOUNT_DATABASE_H

#include <vector>
#include "Account.h" // Account class definition

class AccountDatabase
{
public:
   AccountDatabase(); // constructor loads accounts from Accounts.dat
   ~AccountDatabase(); // destructor saves accounts into Accounts.dat

   // there exists an account containing specified email address
   bool existAccount( string userEmail );

   // determine whether email address and password match those of an Account
   bool authenticateUser( string userEmail, string userPassword );

   void pushBack( Account &newAccount ); // add newAccount at the end of accounts

   // return name of the unique Account object in accounts, containing specified email address
   string getName( string theEmail );

   // return address of the unique Account object in accounts, containing specified email address
   string getAddress( string theEmail );

   // return phone of the unique Account object in accounts, containing specified email address
   string getPhone( string theEmail );

   // return cart of the unique Account object in accounts, containing specified email address
   int* getCart( string theEmail );
private:
   vector< Account > accounts; // vector of the customer's accounts

   void loadAccountDetails();
   void saveAccountDetails();

   // return a pointer to the unique Account object in accounts, containing specified email address
   Account* getAccount( string theEmail );
}; // end class AccountDatabase

#endif // ACCOUNT_DATABASE_H