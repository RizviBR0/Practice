#include <iostream>
using namespace std;

int main()
{
    int row, col, j, i;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    for (i = 1; i <= row; ++i) {
      for (j = 1; j <= i; ++j) {
         cout << "* ";
      }
      cout << endl;
   }
}