#include <iostream>
#include "Registration.h" // Registration class definition

Registration::Registration( AccountDatabase &theAccountDatabase )
   : accountDatabase( theAccountDatabase )
{
}

void Registration::run()
{
	string email;

	while (true)
	{
		cout << "\nEnter your e-mail address (account number) (0 to end): ";
		cin >> email;

		if (email == "0")
			return;

		if (accountDatabase.existAccount(email))
			cout << "\nAn account already exists with the e-mail!\n";
		else
		{
			newAccount.setEmail(email);

			string password;
			cout << "\nEnter your password: ";
			cin >> password;
			newAccount.setPassword(password);

			string name;
			cout << "\nEnter your name: ";
			cin >> name;
			newAccount.setName(name);

			string address;
			cout << "\nEnter your physical address: ";
			cin >> address;
			newAccount.setAddress(address);

			string phone;
			cout << "\nEnter your phone number: ";
			cin >> phone;
			newAccount.setPhone(phone);

			accountDatabase.pushBack(newAccount);

			cout << "\nRegistration Successfully!\n";
			return;
		}
	}
	
}