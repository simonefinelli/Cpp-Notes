/*
   Simox's Carpet Cleaning Service
   Charges $30 per room
   Sales tax rate is 6%
   Estimates are valid for 30 days
   
   Prompt the user for the number of rooms they would like cleaned
   and provide an estimate such as:
   
      Estimate for carpet cleaning service
      Number of rooms: 2
      Price per room:  $30
      Cost: $60
      Tax: $3.6
      ====================================
      Total estimate: $63.6
      This estimate is valid for 30 days
*/

#include <iostream>

using namespace std;

const float PRICE_PER_ROOM = 42.42;
const float PERCENTAGE = 0.06;

int main() {
   cout << "Hello, welcome to Simox's Carpet Cleaning Service\n" << endl;
   cout << "How many rooms would you like cleaned? ";
   
   int number_rooms = 0;
   cin >> number_rooms;
   
   cout << "\nEstimate for carpet clening service" << endl;
   cout << "Number of rooms: " << number_rooms << endl;
   cout << "Price per room: $" << PRICE_PER_ROOM << endl;
   float cost = PRICE_PER_ROOM * number_rooms;
   cout << "Cost: $" << cost << endl;
   float tax = cost * PERCENTAGE;
   cout << "Tax: $" << tax << endl;
   cout << "==================================" << endl;
   cout << "Total estimate: $" << cost + tax << endl;
   cout << "Estimates are valid for 30 days" << endl;
   
   cout << endl; 
   
   return 0;
}
