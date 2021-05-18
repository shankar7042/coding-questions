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

void unionSorted(int a1[], int size1, int a2[], int size2)
{
    int i = 0,
        j = 0,
        k = 0;
    int result[size1 + size2];

    while (i < size1 && j < size2)
    {
        if (a1[i] < a2[j])
        {
            result[k++] = a1[i++];
        }
        else if (a1[i] > a2[j])
        {
            result[k++] = a2[j++];
        }
        else
        {
            result[k++] = a1[i++];
            j++;
        }
    }

    while (i < size1)
    {
        result[k++] = a1[i++];
    }
    while (j < size2)
    {
        result[k++] = a2[j++];
    }

    cout << "k = " << k << endl;
    printArr(result, k);
}

void intersectionSorted(int a1[], int size1, int a2[], int size2)
{
    int i = 0,
        j = 0,
        k = 0;
    int result[size1 + size2];

    while (i < size1 && j < size2)
    {
        if (a1[i] < a2[j])
        {
            i++;
        }
        else if (a1[i] > a2[j])
        {
            j++;
        }
        else
        {
            result[k++] = a1[i++];
            j++;
        }
    }

    cout << "k = " << k << endl;
    printArr(result, k);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif

    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    inputArr(arr1, n1);
    inputArr(arr2, n2);
    printArr(arr1, n1);
    printArr(arr2, n2);
    unionSorted(arr1, n1, arr2, n2);
    intersectionSorted(arr1, n1, arr2, n2);
    return 0;
}