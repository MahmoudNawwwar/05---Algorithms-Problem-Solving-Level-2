// This program generates random numbers within a specified range using a random number generator.

#include <iostream>
#include <cstdlib>
using namespace std;

void RandomNumber()
{
    // Function to generate a random number within a given range
    cout << char( rand() % (122 - 97 + 1) + 97)<<endl;
    cout << char(rand() % (90 - 65 + 1) + 65) << endl;
    cout << char(rand() % (96 - 91 + 1) + 91) << endl;
    cout << (rand() % (9 - 0 + 1) + 0) << endl;

    
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

   RandomNumber() ;
   

    return 0;
}
