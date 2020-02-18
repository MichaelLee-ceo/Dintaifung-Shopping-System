#include <iostream>
#include "Login.h" // Registration class definition
#include "OrderDatabase.h" // OrderDatabase class definition
#include "MakingOrder.h" // MakingOrder class definition
#include "OrderHistory.h" // Member class definition

Login::Login( AccountDatabase &theAccountDatabase )
   : accountDatabase( theAccountDatabase )
{
}

void Login::run()
{
	string email;
	string password;

	while (true)
	{
		cout << "\nEmail (Account number) (0 to end): ";
		cin >> email;

		if (email == "0")
			return;

		if (!accountDatabase.existAccount(email))
		{
			cout << "\nNo account exists with the e-mail!" << endl;
			continue;
		}
			
		cout << "\nPassword: ";
		cin >> password;

		if (accountDatabase.authenticateUser(email, password))
			break;
		else
			cout << "Invalid password. Please try again.\n";
	}

	int choice;
	OrderDatabase orderDataBase;

	OrderHistory orderHistory(email, accountDatabase, orderDataBase);
	MakingOrder makingOrder(email, accountDatabase, orderDataBase);

	while ((choice = enterChoice()) != 3)
	{
		switch (choice)
		{
		case 1:
			makingOrder.run();
			break;
		case 2:
			orderHistory.run();
			break;
		default:
			cerr << "\nIncorrect choice" << endl;
			break;
		}
	}
}

int Login::enterChoice()
{
   cout << "\nEnter your choice\n"
      << "1. Making order\n"
      << "2. Order history\n"
      << "3. Back to top\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}