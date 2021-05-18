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

// Brute force O(n^2) Solution
// int getPairsCount(int arr[], int n, int k)
// {
// 	int count = 0;
// 	for (int i = 0; i < n - 1; i++)
// 	{
// 		for (int j = i + 1; j < n; j++)
// 		{
// 			if (arr[i] + arr[j] == k)
// 				count++;
// 		}
// 	}
// 	return count;
// }


// Optimal Solution O(n) Solution
int getPairsCount(int arr[], int n, int k)
{
	int count = 0, x;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		x = k - arr[i];
		if (m[x] == 0)
		{
			m[arr[i]]++;
		}
		else
		{
			count += m[x];
			m[arr[i]]++;
		}
	}
	return count;
}

int main()
{
	int n, k, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int arr[n];
		inputArr(arr, n);
		printArr(arr, n);
		// getPairsCount(arr, n, k);
		cout << getPairsCount(arr, n, k);
		cout << endl;
	}
	return 0;
}