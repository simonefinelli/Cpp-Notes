/*
 * Arrays 
 */

#include <iostream>

using namespace std;


int main(){
   
   char vowels[] = {'a', 'e', 'i', 'o', 'u'};
   cout << "The fist vowels is: " << vowels[0] << endl;
   cout << "The last vowels is: " << vowels[4] << endl;
   
   double hi_temps[4] = {9.3, 41.4, 23.1, 24.9};
   cout << "\nThe first temperature is: " << hi_temps[0] << endl;
   hi_temps[0] = 15.8;
   cout << "The first temperature now is: " << hi_temps[0] << endl;
   
   int some_numbers[5];  // random initialization
   cout << "\nThe 1st num is:" << some_numbers[0] << endl;
   cout << "The 2nd num is: " << some_numbers[1] << endl;
   cout << "The 3rd num is: " << some_numbers[2] << endl;
   cout << "The 4th num is: " << some_numbers[3] << endl;
   cout << "The 5th num is: " << some_numbers[4] << endl;
   
   int some_numbers_1[5] = {0};  // all 0 initialization. Only with 0 works. We can also use {}. 
   cout << "\nThe 1st num is:" << some_numbers_1[0] << endl;
   cout << "The 2nd num is: " << some_numbers_1[1] << endl;
   cout << "The 3rd num is: " << some_numbers_1[2] << endl;
   cout << "The 4th num is: " << some_numbers_1[3] << endl;
   cout << "The 5th num is: " << some_numbers_1[4] << endl;
   
   int some_numbers_2[5] = {-1, 41};  // partial initialization
   cout << "\nThe 1st num is:" << some_numbers_2[0] << endl;
   cout << "The 2nd num is: " << some_numbers_2[1] << endl;
   cout << "The 3rd num is: " << some_numbers_2[2] << endl;
   cout << "The 4th num is: " << some_numbers_2[3] << endl;
   cout << "The 5th num is: " << some_numbers_2[4] << endl;
   
   cout << "Array location memory address: " << some_numbers_2 << endl;
   
   return 0;
}