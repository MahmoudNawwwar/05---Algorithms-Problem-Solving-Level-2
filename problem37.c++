
// This program allows the user to input numbers into an array dynamically, displays the array, and shows its length.

#include <iostream>
using namespace std;

// Function to read a number from the user
int ReadNumber()
{
    int number;
    cout << "\nPlease enter a number: ";
    cin >> number;
    return number;
}

// Function to add a number to the array and increment the length
void AddArrayElement(int number, int arr[100], int& arrLength)
{
    arr[arrLength] = number;
    arrLength++;
}

// Function to let the user input numbers into the array
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool addMore = true;
    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);
        cout << "\nDo you want to add more numbers? [0]: No, [1]: Yes? ";
        cin >> addMore;
    } while (addMore);
}

// Function to print all elements of the array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[100];       // Array to store user input
    int arrLength = 0;  // Tracks the number of elements in the array

    InputUserNumbersInArray(arr, arrLength);

    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);

    return 0;
}
