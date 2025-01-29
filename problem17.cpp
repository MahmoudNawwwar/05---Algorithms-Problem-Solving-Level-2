// This program generates and prints all possible three-letter combinations from "AAA" to "ZZZ" using uppercase letters.

#include <iostream>
#include <string>
using namespace std;

void PrintWordsNumOfTrial()
{
    string s;
    cin >> s;
    int counter = 1;
    cout << "\n";
    string word = "";
    for (int i = 65; i <= 90; i++) // Outer loop for the first letter
    {
        for (int j = 65; j <= 90; j++) // Middle loop for the second letter
        {
            for (int k = 65; k <= 90; k++) // Inner loop for the third letter
            {
                word = word + char(i); // Append first letter
                word = word + char(j); // Append second letter
                word = word + char(k); // Append third letter
                cout << "tria(" << counter++ << "): " << word << endl;  // Print the word
                if (word == s) return;
                word = "";             // Reset the word
            }
        }
    }
    cout << "\n____________________________\n";
}

int main()
{
    PrintWordsFromAAAtoZZZ();
    return 0;
}
