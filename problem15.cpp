// This program reads a positive number and prints a letter pattern, starting from 'A', where each row repeats the corresponding letter.

#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintLetterPattern(int Number)
{
    cout << "\n";
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    char a, b, c;
    a = 65;
    b = a;
    c = a;
    for (int i = 65; i <= int('Z'); i++) {
        for (int j = 65; j <= int('Z'); j++)
        {
            for (int y = 65; y <= int('Z'); y++)
            {
                cout << char(a) << char(b) << char(c) << endl;
                a++; b++;c++;
            }
        }

    }



}
