
// This program rounds a float number using a custom function and compares the result with C++'s built-in round function.

#include <iostream>
using namespace std;

// Function to get the fractional part of a float number
float GetFractionPart(float Number)
{
    return Number - int(Number);
}

// Custom rounding function
int MyRound(float Number)
{
    int IntPart = int(Number);                // Extract integer part
    float FractionPart = GetFractionPart(Number); // Get fractional part

    if (abs(FractionPart) >= 0.5)             // Check if fractional part requires rounding
    {
        if (Number > 0)
            return ++IntPart;                 // Round up for positive numbers
        else
            return --IntPart;                 // Round down for negative numbers
    }
    else
    {
        return IntPart;                       // Return the integer part if rounding is not needed
    }
}

// Function to read a float number from the user
float ReadNumber()
{
    float Number;
    cout << "Please enter a float number? ";
    cin >> Number;
    return Number;
}

int main()
{
    float Number = ReadNumber();

    // Display results of custom and built-in round functions
    cout << "My Round Result : " << MyRound(Number) << endl;
    cout << "C++ Round Result: " << round(Number) << endl;

    return 0;
}
