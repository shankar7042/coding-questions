#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getMinDiff(int arr[], int n, int k) {
    int minimum = 0, maximum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            arr[i] += k;
        }
        else
        {
            arr[i] -= k;
        }
    }
    printArr(arr, n);
    sort(arr, arr + n);
    printArr(arr, n);
    minimum = arr[0];
    maximum = arr[n - 1];
    return maximum - minimum;
}

int main()
{
    int n , k;
    cin >> k >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr, n);
    cout << getMinDiff(arr, n, k);
    return 0;
}