#include <iostream>
using namespace std;

int main()
{
    int input;
    float celsius, fahrenheit;

    cout << "1. Celsius to Fahrenheit" << endl
         << "2. Fahrenheit to Celsius" << endl
         << "--------------------------------" << endl
         << "Enter your choice: ";
    cin >> input;
    cout << "\n";

    switch (input)
    {
    case 1:
        cout << "Enter the temperature in Celsius: ";
        cin >> celsius;

        fahrenheit = (celsius * 1.8) + 32;
        cout << "The temperature in Fahrenheit is: " << fahrenheit << endl;
        break;

    case 2:
        cout << "Enter the temperature in Fahrenheit: ";
        cin >> fahrenheit;

        celsius = (fahrenheit - 32) / 1.8;
        cout << "The temperature in Celsius is: " << celsius << endl;
        break;

    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}