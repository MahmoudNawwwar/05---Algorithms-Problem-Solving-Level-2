
// This program allows the user to input numbers into an array dynamically, displays the array, and shows its length.

#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number? ";
    cin >> Number;
    return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    // Adds a new element to the array and increments its length
    arr[arrLength] = Number;
    arrLength++;
}

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;
    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);
        cout << "\nDo you want to add more numbers? [0]: No, [1]: Yes? ";
        cin >> AddMore;
    } while (AddMore);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[100], arrLength = 0;
    InputUserNumbersInArray(arr, arrLength);
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);
    return 0;
}
