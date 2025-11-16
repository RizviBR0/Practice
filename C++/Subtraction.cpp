#include <iostream>
using namespace std;

void subtract(int &x, int y)
{
    x = x - y;
}

int main()
{
    int x = 10, y = 4;
    cout << "Before Subtraction: X = " << x << ", Y = " << y << endl;
    subtract(x, y);
    cout << "After Subtraction: X = " << x << ", Y = " << y << endl;
    return 0;
}
