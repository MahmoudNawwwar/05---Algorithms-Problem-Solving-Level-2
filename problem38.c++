
// This program fills an array with random numbers, prints it, and allows adding new elements to the array.

#include <iostream>
using namespace std;

// Function to generate a random number within a given range
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Function to fill an array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function to print all elements in the array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to add a new element to the array and increment its length
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

int main()
{
    // Seeds the random number generator in C++
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0;

    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray elements:\n";
    PrintArray(arr, arrLength);

    // Example of adding a new element to the array
    int newElement;
    cout << "\nEnter a number to add to the array: ";
    cin >> newElement;

    AddArrayElement(newElement, arr, arrLength);

    cout << "\nArray after adding the new element:\n";
    PrintArray(arr, arrLength);

    return 0;
}
