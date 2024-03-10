#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int number;
    while (1)
    {
        int randomNumber = rand() % 5 + 1;
        cout << "Enter a number (1-5): ";
        cin >> number;

        if (number == randomNumber)
        {
            cout << "You guessed it right!" << endl << endl;
        }
        else
        {
            cout << "You guessed it wrong! The number was " << randomNumber << endl << endl;
        }
    }
}