#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";

    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int max = arr[1];

    for (int i = 2; i <= n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    cout << "Max number is : " << max << endl;
}