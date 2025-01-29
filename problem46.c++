
// This program calculates the absolute value of a number using a custom function and compares it with C++'s built-in abs function.

#include <iostream>
using namespace std;

// Custom function to compute the absolute value of a number
float MyABS(float Number)
{
    if (Number > 0)
        return Number;
    else
        return Number * -1;
}

// Function to read a number from the user
float ReadNumber()
{
    float Number;
    cout << "Please enter a number? ";
    cin >> Number;
    return Number;
}

int main()
{
    float Number = ReadNumber();

    // Display results of custom and built-in absolute value functions
    cout << "My ABS Result: " << MyABS(Number) << endl;
    cout << "C++ ABS Result: " << abs(Number) << endl;

    return 0;
}
