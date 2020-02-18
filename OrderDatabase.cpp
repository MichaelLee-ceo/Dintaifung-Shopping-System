// OrderDatabase.cpp
// Member-function definitions for class OrderDatabase.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "OrderDatabase.h" // OrderDatabase class definition

// OrderDatabase default constructor initializes orders
OrderDatabase::OrderDatabase()
{
   loadOrderDetails();
} // end OrderDatabase default constructor

// OrderDatabase destructor
OrderDatabase::~OrderDatabase()
{
   saveOrderDetails();
} // end OrderDatabase destructor

void OrderDatabase::loadOrderDetails()
{
	ifstream inFile("Orders.dat", ios::binary);
	Order o;

	while (inFile.read((char *)&o, sizeof(o)))
		orders.push_back(o);

	inFile.close();
}

string OrderDatabase::generateOrderNumber() const
{
   srand( static_cast< unsigned int >( time( nullptr ) ) );

   string orderNumber;
   do
   {
      orderNumber.push_back( rand() % 26 + 'A' );
      for( int i = 1; i <= 9; i++ )
         orderNumber.push_back( rand() % 10 + '0' );
   } while( existOrder( orderNumber ) );

   return orderNumber;
}

void OrderDatabase::pushBack( Order &newOrder )
{
   orders.push_back( newOrder );
}

bool OrderDatabase::existOrders( string email ) const
{
   for( size_t i = 0; i < orders.size(); i++ )
      if( orders[ i ].getEmail() == email )
         return true;
   return false;
}

void OrderDatabase::displayOrders( string email, string name ) const
{
	cout << "\nYour order history:\n";
	cout << "Code    Order no.     Name\n";
	
	vector<Order> buffer;
	int find = 0;
	int choice;

	for (int i = 0; i < orders.size(); i++)
	{
		if (orders[i].getEmail() == email)
		{
			buffer.push_back(orders[i]);
			find++;
			cout << setw(4) << right << find << setw(13) << right << orders[i].getOrderNumber() << setw(9) << right << name << endl;
		}
	}

	cout << "Choose a code (1 ~ " << find << ") ";
	cin >> choice;

	cout << "\nYour order details:\n";
	cout << "Item Code                                        Item  Price  Quantity  Subtotal\n";
	buffer[choice - 1].displayOrderDetails();
}

void OrderDatabase::saveOrderDetails()
{
	ofstream outFile("Orders.dat", ios::binary);
	for (int i = 0; i < orders.size(); i++)
		outFile.write((char *)&orders[i], sizeof(orders[i]));

	outFile.close();
}

bool OrderDatabase::existOrder( string orderNumber ) const
{
   for( size_t i = 0; i < orders.size(); i++ )
      if( orders[ i ].getOrderNumber() == orderNumber )
         return true;
   return false;
}