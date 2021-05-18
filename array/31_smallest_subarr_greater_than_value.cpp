#include<bits/stdc++.h>
using namespace std;

// int sb(int arr[], int n, int x)
// {
// 	int start = 0, end = 0;
// 	int minLen = INT_MAX;
// 	int curr_sum = 0;
// 	while (end < n)
// 	{
// 		while (curr_sum <= x && end < n)
// 			curr_sum += arr[end++];

// 		while (curr_sum > x && start < n)
// 		{
// 			minLen = min(minLen, end - start);
// 			curr_sum -= arr[start++];
// 		}
// 	}
// 	return minLen;
// }

int sb(int arr[], int n, int x)
{
	int start = 0, end = 0;
	int minLen = INT_MAX;
	int curr_sum = 0;
	int a, b;
	while (end < n)
	{
		while (curr_sum <= x && end < n)
			curr_sum += arr[end++];

		while (curr_sum > x && start < n)
		{
			if (end - start < minLen)
			{
				minLen = end - start;
				a = start;
				b = end;
			}
			curr_sum -= arr[start++];
		}
	}
	for (int i = a; i < b; i++)
		cout << arr[i] << " ";
	cout << endl;
	return minLen;
}

int main()
{
	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << sb(arr, n, x);
}