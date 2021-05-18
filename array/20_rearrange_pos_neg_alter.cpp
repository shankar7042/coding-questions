#include <bits/stdc++.h>
using namespace std;

// O(n) and S(1) but this function change the order of numbers in the array
// void rearrange(int arr[], int n)
// {
//     int i = 0, j = n - 1;
//     while (i < j)
//     {
//         if ((arr[i] < 0) && (arr[j] > 0))
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//         else if (arr[i] > 0)
//             i++;
//         else if (arr[j] < 0)
//             j--;
//     }
//     int k = 0;
//     if (i == 0 || i == n)
//         return;
//     while (k < n && i < n)
//     {
//         swap(arr[k], arr[i]);
//         k += 2;
//         i++;
//     }
// }

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
    int outofplace = -1;

    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
        if (outofplace == -1)
        {
            if (((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index] < 0) && (index & 0x01)))
            {
                outofplace = index;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    int arr[] = {-5, -2, 5, 2,
                 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;
}