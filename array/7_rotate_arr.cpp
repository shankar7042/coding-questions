#include <iostream>
using namespace std;

void inputArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateArr(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        swap(arr[i], arr[size - 1]);
    }
}

void rotateArr2(int arr[], int size)
{
    int last = arr[size - 1];
    for (int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];
        inputArr(arr, size);
        rotateArr2(arr, size);
        printArr(arr, size);
    }
    return 0;
}