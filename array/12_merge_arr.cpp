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

// O(n * m) Solution
void merge(int arr1[], int arr2[], int n, int m)
{
	int i = 0,
	    j = 0;

	while (i < n)
	{
		j = 0;
		if (arr1[i] > arr2[j])
		{
			swap(arr1[i], arr2[j]);
			while (j < m - 1)
			{
				if (arr2[j] > arr2[j + 1])
				{
					swap(arr2[j], arr2[j + 1]);
					j++;
				}
				else
					break;
			}
		}
		i++;
	}
}

// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void merge2(int arr1[], int arr2[], int n, int m)
{
	int gap = n + m, i, j;
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
	{
		for (i = 0; i + gap <= n; i++)
			if (arr1[i] > arr1[i + gap])
				swap(arr1[i], arr1[i + gap]);

		for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
		{
			if (arr1[i] > arr2[j])
			{
				swap(arr1[i], arr2[j]);
			}
		}

		if (j < m) {
			for (j = 0; j + gap <= m; j++)
			{
				if (arr2[j] > arr2[j + gap])
				{
					swap(arr2[j], arr2[j + gap]);
				}
			}
		}
	}
}

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	int a[n1], b[n2];
	inputArr(a, n1);
	inputArr(b, n2);
	printArr(a, n1);
	printArr(b, n2);
	merge2(a, b, n1, n2);
	cout << endl;
	// printArr(a, n1);
	// printArr(b, n2);
	for (int i = 0; i < n1; i++) {
		cout << a[i] << " ";
	}
	for (int i = 0; i < n2; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
