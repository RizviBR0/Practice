#include <iostream>
using namespace std;

class safeArray
{
    int arr[2][3], row, column;

public:
    void set(int row, int column, int value)
    {
        if (row >= 0 && row < 2 && column >= 0 && column < 3)
        {
            arr[row][column] = value;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }

    int get(int row, int column)
    {
        if (row >= 0 && row < 2 && column >= 0 && column < 3)
        {
            return arr[row][column];
        }
        else
        {
            cout << "Index out of range" << endl;
            return -1;
        }
    }
};

void display(safeArray s)
{
    cout << "Values are :" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << s.get(i, j) << "\t";
        }
    }
}

int main()
{
    int value;
    safeArray s;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter value [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> value;
            s.set(i, j, value);
        }
    }

    display(s);
}