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

// O(n^2) solution
int minJumps(int arr[], int n)
{
	int jumps[n];

	if (n == 0 || arr[0] == 0)
		return -1;

	jumps[0] = 0;
	for (int i = 1; i < n; i++)
	{
		jumps[i] = INT_MAX;
		for (int j = 0; j < i; j++)
		{
			if (i <= j + arr[j] && jumps[j] != INT_MAX)
			{
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	printArr(jumps, n);
	if (jumps[n - 1] == INT_MAX)
		return -1;
	return jumps[n - 1];
}

// O(n) solution
int minJumps2(int arr[], int n)
{
	if (n == 1)
		return 0;

	if (arr[0] == 0)
		return -1;

	int maxReach = arr[0];
	int steps = arr[0];
	int jumps = 1;

	for (int i = 1; i < n; i++)
	{
		if (i == n - 1)
			return jumps;

		maxReach = max(maxReach, i + arr[i]);

		steps--;

		if (steps == 0)
		{
			jumps++;

			if (i >= maxReach)
				return -1;

			steps = maxReach - i;
		}
	}
	return jumps;
}

int main()
{
	int size;
	cin >> size;
	int arr[size];
	inputArr(arr, size);
	printArr(arr, size);
	cout << endl << "Min Jumps: " << minJumps2(arr, size);
	return 0;
}