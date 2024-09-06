#include <iostream>
using namespace std;

int main()
{
    int n, fib, fib1 = 0, fib2 = 1;

    cout << "Enter a value: ";
    cin >> n;

    cout << fib1 << " " << fib2 << " ";
    for (int i = 1; i < n - 1; i++)
    {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
        cout << fib << " ";
    }
}