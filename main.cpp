#include <iostream>
#include "Login.h" // Registration class definition
#include "Registration.h" // Registration class definition

const char foods[ 15 ][ 44 ] = { "", "Pork XiaoLongBao (12)",
                                     "Steamed Vegetable and Pork Dumplings (8)",
                                     "Steamed Shrimp and Pork Dumplings (8)",
                                     "Steamed Fish Dumplings (8)",
                                     "Steamed Vegetarian Mushroom Dumplings (8)",
                                     "Steamed Shrimp and Pork Shiaomai (12)",
                                     "Pork Buns (5)",
                                     "Vegetable and Ground Pork Buns (5)",
                                     "Red Bean Buns (5)",
                                     "Sesame Buns (5)",
                                     "Taro Buns (5)",
                                     "Vegetarian Mushroom Buns (5)",
                                     "Pork Sticky Rice Buns (5)",
                                     "Red Bean Sticky Rice Buns (5)" };

int enterChoice();

int main()
{
   cout << "Welcome to DintaiFung Shopping Mall!\n";

   AccountDatabase accountDatabase;

   Registration registration( accountDatabase );
   Login login( accountDatabase );

   int choice;

   while ( ( choice = enterChoice() ) != 3 )
   {
      switch ( choice )
      {
         case 1:
				login.run();
            break;
         case 2:
				registration.run();
            break;
         default:
            cerr << "\nIncorrect choice" << endl;
            break;
      }
   }

   cout << endl;
   system( "pause" );
}

int enterChoice()
{
   cout << "\nEnter your choice\n"
        << "1. Login\n"
        << "2. Registration\n"
        << "3. End Program\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}