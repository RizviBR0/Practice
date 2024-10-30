#include <iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int Left[size1], Right[size2];

    // copying the data from arr to temporary array
    for (i = 0; i < size1; i++)
        Left[i] = arr[left + i];

    for (j = 0; j < size2; j++)
        Right[j] = arr[mid + 1 + j];

    // merging of the array
    i = 0;    // intital index of first subarray
    j = 0;    // inital index of second subarray
    k = left; // initial index of parent array

    while (i < size1 && j < size2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // copying the elements from Left[], if any
    while (i < size1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // copying the elements from Right[], if any
    while (j < size2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

// merge sort function
void Merge_Sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Merge_Sort(arr, 0, n - 1);

    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}