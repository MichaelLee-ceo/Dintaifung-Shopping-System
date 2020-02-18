// Login.h
// Login class definition.
#ifndef LOGIN_H
#define LOGIN_H

#include "AccountDatabase.h" // AccountDatabase class definition

class Login
{
public:
   Login( AccountDatabase & ); // constructor initializes data members
   void run(); // start the Login
private:
   AccountDatabase &accountDatabase; // account database
   int enterChoice();
}; // end class Login

#endif