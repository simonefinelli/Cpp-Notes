#include <iostream>

int main(){
   
   // size of operators
   std::cout << "The size of operators in bytes is:\n";
   std::cout << "int: " << sizeof(int) << std::endl;
   std::cout << "float: " << sizeof(float) << std::endl;
   std::cout << "double: " << sizeof(double) << std::endl;
   std::cout << std::endl;
   
   // Character types
   char middle_initial{'S'};
   std::cout << "My middle initial is: " << middle_initial << std::endl;
   
   // Integer types
   unsigned short int exam_score {55};
   std::cout << "My exam score was " << exam_score << std::endl;
   
   int countries_represented {42};
   std::cout << "There were " << countries_represented << " coutries represented in my meeting" <<std::endl;
   
   long people_in_florida {20610000};
   std::cout << "There are about " << people_in_florida << " people in Florida!" <<std::endl;
   
   long long people_on_earth{7'600'000'000};
   std::cout << "There are about " << people_on_earth << " people on Earth!" <<std::endl;
   
   
   // Floating-point types
   float car_payment {401.23};
   std::cout << "Ny car payment is " << car_payment << std::endl;
   
   double pi{3.14159};
   std::cout << "PI is " << pi <<std::endl;

   long double large_amount {2.7e120};
   std::cout << "The number is very big: " << large_amount << std::endl;
   
   // Boolean type
   bool game_over {false};
   std::cout << "Is the game over? " << game_over << std::endl;
   
   /*
    * Overflow examples
    */
   short v1 {30000};
   short v2 {1000};
   short sum {v1 * v2};
    
   std::cout << "The product of " << v1 << " and " << v2 << " is " << sum << std::endl;
   
   
   return 0;
}