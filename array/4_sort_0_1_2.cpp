#include <iostream>
using namespace std;

void inputArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void countSort(int arr[], int size)
{
    int zeros = 0, ones = 0, twos = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            zeros++;
        else if (arr[i] == 1)
            ones++;
        else if (arr[i] == 2)
            twos++;
    }
    int i = 0;
    for (; i < zeros; i++)
        arr[i] = 0;
    for (; i < ones + zeros; i++)
        arr[i] = 1;
    for (; i < zeros + ones + twos; i++)
        arr[i] = 2;
}

void sort012(int arr[], int size)
{
    int low = 0,
        mid = 0,
        high = size - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif

    int size;
    cin >> size;
    int arr[size];
    inputArr(arr, size);
    printArr(arr, size);
    sort012(arr, size);
    printArr(arr, size);
    return 0;
}