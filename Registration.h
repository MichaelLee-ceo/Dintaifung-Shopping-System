// Registration.h
// Registration class definition.
#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "AccountDatabase.h" // AccountDatabase class definition

class Registration
{
public:
   Registration( AccountDatabase &theAccountDatabase ); // constructor initializes data members
   void run(); // start the Registration
private:
   Account newAccount; // a new account
   AccountDatabase &accountDatabase; // account database
}; // end class Registration

#endif