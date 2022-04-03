/* 
 * This program will calculate the area of a room in square meters
 */

#include <iostream>

int main() {
   
   double room_width {0};
   double room_length {0};
   
   std::cout << "Enter the width and the height of the room: ";   
   std::cin >> room_width >> room_length;
   
   std::cout << "The area of the room is: " << room_width * room_length << " sqare meters" << std::endl;
   
   return 0;
}