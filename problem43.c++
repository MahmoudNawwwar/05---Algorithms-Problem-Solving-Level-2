
// This program generates an array of random numbers, prints it, and counts how many even numbers are in the array.

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

// Function to print all elements of the array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to count the number of even numbers in the array
int EvenCount(int arr[100], int arrLength)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    // Seeds the random number generator in C++
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Count and display the number of even numbers
    cout << "\nEven Numbers count is: ";
    cout << EvenCount(arr, arrLength) << endl;

    return 0;
}
