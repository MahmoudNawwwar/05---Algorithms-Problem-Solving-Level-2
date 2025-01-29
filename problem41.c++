
// This program checks if an array is a palindrome, meaning it reads the same backward as forward.

#include <iostream>
using namespace std;

// Function to fill the array with predefined values
void FillArray(int arr[100], int& arrLength)
{
    // Example array: 10 20 30 30 20 10
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

// Function to print all elements of the array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to check if the array is a palindrome
bool IsPalindromeArray(int arr[100], int Length)
{
    for (int i = 0; i < Length / 2; i++)
    {
        if (arr[i] != arr[Length - i - 1])
        {
            return false; // Array is not a palindrome
        }
    }
    return true; // Array is a palindrome
}

int main()
{
    int arr[100], Length = 0;

    // Fill the array with predefined values
    FillArray(arr, Length);

    cout << "\nArray Elements:\n";
    PrintArray(arr, Length);

    // Check if the array is a palindrome
    if (IsPalindromeArray(arr, Length))
        cout << "\nYes, the array is a Palindrome\n";
    else
        cout << "\nNo, the array is NOT a Palindrome\n";

    return 0;
}
