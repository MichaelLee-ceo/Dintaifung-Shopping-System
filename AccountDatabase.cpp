// AccountDatabase.cpp
// Member-function definitions for class AccountDatabase.
#include <iostream>
#include <fstream>
#include "AccountDatabase.h" // AccountDatabase class definition

// AccountDatabase default constructor initializes accounts
AccountDatabase::AccountDatabase()
{
   loadAccountDetails();
} // end AccountDatabase default constructor

// AccountDatabase destructor
AccountDatabase::~AccountDatabase()
{
   saveAccountDetails();
} // end AccountDatabase destructor

void AccountDatabase::loadAccountDetails()
{
	ifstream inFile("Accounts.dat", ios::binary);
	Account a;

	while (inFile.read((char *)&a, sizeof(a)))
		accounts.push_back(a);

	inFile.close();
}

// determine whether user-specified email address and password match
// those of an account in the database
bool AccountDatabase::existAccount( string userEmail )
{
   // attempt to retrieve the account with the email address
   Account * const userAccountPtr = getAccount( userEmail );

   if( userAccountPtr == nullptr )
      return false;
   else
      return true; // account not found, so return false
} // end function authenticateUser

// determine whether user-specified email address and password match
// those of an account in the database
bool AccountDatabase::authenticateUser( string userEmail, string userPassword )
{
   // attempt to retrieve the account with the email address
   Account * const userAccountPtr = getAccount( userEmail );

   // if account exists, return result of Account function validatePassword
   if ( userAccountPtr == nullptr )
      return false;
   else
      return userAccountPtr->validatePassword( userPassword ); // account not found, so return false
} // end function authenticateUser

void AccountDatabase::pushBack( Account &newAccount )
{
   accounts.push_back( newAccount );
}

string AccountDatabase::getName( string theEmail )
{
   Account *accountPtr = getAccount( theEmail );
   if( accountPtr == nullptr )
      return string( "" );
   else
      return accountPtr->getName();
}

string AccountDatabase::getAddress( string theEmail )
{
   Account *accountPtr = getAccount( theEmail );
   if( accountPtr == nullptr )
      return string( "" );
   else
      return accountPtr->getAddress();
}

string AccountDatabase::getPhone( string theEmail )
{
   Account *accountPtr = getAccount( theEmail );
   if( accountPtr == nullptr )
      return string( "" );
   else
      return accountPtr->getPhone();
}

int* AccountDatabase::getCart( string theEmail )
{
   Account *accountPtr = getAccount( theEmail );
   if( accountPtr == nullptr )
      return nullptr;
   else
      return accountPtr->getCart();
}

void AccountDatabase::saveAccountDetails()
{
	ofstream outFile("Accounts.dat", ios::binary);
	for (int i = 0; i < accounts.size(); i++)
		outFile.write((char *)&accounts[i], sizeof(accounts[i]));

	outFile.close();
}

// retrieve Account object containing specified email address
Account* AccountDatabase::getAccount( string theEmail )
{
	for (int i = 0; i < accounts.size(); i++)
		if (accounts[i].getEmail() == theEmail)
			return &accounts[i];

   return nullptr; // if no matching account was found, return nullptr
} // end function getAccount