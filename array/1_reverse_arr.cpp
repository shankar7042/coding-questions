#include <bits/stdc++.h>
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

void reverseArr(int arr[], int size)
{
	int temp;
	for (int i = 0, j = size - 1; i < size / 2; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void reverseArrRecursive(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	else
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		reverseArrRecursive(arr, start + 1, end - 1);
	}
}

int main()
{
	int size;
	cin >> size;
	int arr[size];
	inputArr(arr, size);
	printArr(arr, size);
	reverseArr(arr, size);
	printArr(arr, size);
	reverseArrRecursive(arr, 0, size - 1);
	printArr(arr, size);
	return 0;
}