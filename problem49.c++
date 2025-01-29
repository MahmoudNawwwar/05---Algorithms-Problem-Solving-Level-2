
// This program calculates the floor of a float number using a custom function and compares it with C++'s built-in floor function.

#include <iostream>
#include <cmath> // For the built-in floor function
using namespace std;

// Custom function to compute the floor of a float number
int MyFloor(float Number)
{
    if (Number >= 0)
        return int(Number);      // For positive numbers, floor is the integer part
    else
        return int(Number) - 1;  // For negative numbers, subtract 1 from the integer part
}

// Function to read a float number from the user
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

    // Display results of custom and built-in floor functions
    cout << "My Floor Result : " << MyFloor(Number) << endl;
    cout << "C++ floor Result : " << floor(Number) << endl;

    return 0;
}
