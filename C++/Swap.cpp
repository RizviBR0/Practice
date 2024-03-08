#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 6, b = 3;
    cout << "Before swap: X = " << a << " Y = " << b << endl;
    swap(a, b);
    cout << "After swap: X = " << a << " Y = " << b << endl;
}