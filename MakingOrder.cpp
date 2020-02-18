#include <iostream>
#include <iomanip>
#include "MakingOrder.h" // MakingOrder class definition

MakingOrder::MakingOrder( string theEmail, AccountDatabase &theAccountDatabase, OrderDatabase &theOrderDatabase )
   : email( theEmail ),
     accountDatabase( theAccountDatabase ),
     orderDatabase( theOrderDatabase )
{
}

void MakingOrder::run()
{
	currentAccount.setEmail(email);
	currentAccount.setName(accountDatabase.getName(email));
	currentAccount.setAddress(accountDatabase.getAddress(email));
	currentAccount.setPhone(accountDatabase.getPhone(email));

	int foodcode;
	int amount;
	int carts[15] = { 0 };
	currentAccount.setCart(carts);

	int choice = 1;
	int first = true;

	do
	{
		switch (choice)
		{
		case 1:
			if (first)
			{
				currentAccount.displayCart();
				first = false;
			}

			cout << "\nEnter foods code: ";
			cin >> foodcode;
			cout << "\nEnter quantity: ";
			cin >> amount;

			carts[foodcode] = amount;
			currentAccount.setCart(carts);

			currentAccount.displayCart();
			break;
		case 2:
			checkout();
			return;
		default:
			cerr << "\nIncorrect choice" << endl;
			break;
		}

	} while ((choice = enterChoice()) != 3);
}

int MakingOrder::enterChoice()
{
   cout << "\n1. Continue Shopping\n"
        << "2. Proceed to Checkout\n"
        << "3. Abandon\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}

void MakingOrder::checkout()
{
	Order currentOrder;
	string orderNumber = orderDatabase.generateOrderNumber();

	currentOrder.setOrderNumber(orderNumber);
	currentOrder.setEmail(currentAccount.getEmail());
	currentOrder.setOrderDetails(currentAccount.getCart());

	orderDatabase.pushBack(currentOrder);

	cout << "\nOrder Number: " << currentOrder.getOrderNumber() << endl;
	cout << "Full Name: " << currentAccount.getName() << endl;
	cout << "Shipping Address: " << currentAccount.getAddress() << endl;
	cout << "Phone Number: " << currentAccount.getPhone() << endl;
	cout << "Bank account: ¦X§@ª÷®w 0062013162077139" << endl;

	cout << "\nItem Code                                        Item     Price  Quantity  Subtotal" << endl;
	currentAccount.displayOrders();
}