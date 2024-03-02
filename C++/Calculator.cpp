#include <iostream>
using namespace std;

void add(int a, int b)
{
    cout << "Sum is : " << a + b << "\n" << endl;
}

void subtract(int a, int b)
{
    cout << "Difference is : " << a - b << "\n" << endl;
}

void multiply(int a, int b)
{
    cout << "Product is : " << a * b << "\n" << endl;
}

void divide(int a, int b)
{
    cout << "Quotient is : " << a / b << "\n" << endl;
}

int main()
{
    while (1)
    {
        int a, b, input;

        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "------------------------\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n------------------------\n";
        cout << "Enter your choice: ";
        cin >> input;

        switch (input)
        {
        case 1:
            add(a, b);
            break;

        case 2:
            subtract(a, b);
            break;

        case 3:
            multiply(a, b);
            break;

        case 4:
            divide(a, b);
            break;

        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid input\n";
        }
    }
}