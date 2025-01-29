// This program generates random characters of specified types (small letter, capital letter, special character, or digit).

#include <iostream>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
    // Function to generate a random number within a specified range
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void GetRandomCharacter()
{
    for (int i = 1; i <= 16; i++)
    {
        cout << RandomNumber();
        if ((i % 4) and (i != 16) == 0) cout << '-';
    }
    cout << endl;


}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    GetRandomCharacter();GetRandomCharacter()
        GetRandomCharacter();GetRandomCharacter();
  

    return 0;
}
