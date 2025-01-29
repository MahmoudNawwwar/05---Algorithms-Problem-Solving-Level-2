
// This program copies distinct elements from one array to another and prints both arrays.

#include <iostream>
using namespace std;

// Function to fill an array with predefined values
void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

// Function to print the elements of an array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to find the position of a number in the array
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i; // Return the index
    }
    return -1; // Number not found
}

// Function to check if a number exists in the array
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

// Function to add a new element to an array
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

// Function to copy distinct numbers from one array to another
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

int main()
{
    int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;

    // Fill the source array with predefined values
    FillArray(arrSource, SourceLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arrSource, SourceLength);

    // Copy distinct numbers to the destination array
    CopyDistinctNumbersToArray(arrSource, arrDestination, SourceLength, DestinationLength);

    cout << "\nArray 2 distinct elements:\n";
    PrintArray(arrDestination, DestinationLength);

    return 0;
}
