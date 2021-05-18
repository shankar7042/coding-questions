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
		cout << arr[i] << " ";
	cout << endl;
}

void rearrange(int arr[], int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			if (i != j)
			{
				swap(arr[i], arr[j]);
			}
			j++;
		}
	}
}

void rearrangePart2(int arr[], int size)
{
	int low = 0;
	int high = size - 1;
	while (low < high)
	{
		if (arr[low] > 0)
		{
			if (arr[high] < 0)
			{
				swap(arr[low], arr[high]);
				low++;
			}
			high--;
		}
		else
		{
			low++;
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
	rearrangePart2(arr, size);
	printArr(arr, size);
	return 0;
}
