#include<bits/stdc++.h>
using namespace std;

// O(n^2) Solution
// int largestSubarrayLen(int arr[], int n)
// {
// 	int len = INT_MIN;
// 	int sum = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		sum = 0;
// 		for (int j = i; j < n; j++)
// 		{
// 			sum += arr[j];
// 			if (sum == 0)
// 			{
// 				len = max(len, j - i + 1);
// 				for (int k = i; k <= j; k++)
// 					cout << arr[k] << " ";
// 				cout << endl;
// 			}
// 		}
// 	}
// 	return len;
// }

int largestSubarrayLen(int arr[], int n)
{
	unordered_map<int, int> m;
	int len = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum == 0)
		{
			len = i + 1;
		}
		else
		{
			// sum found on to the map
			if (m.find(sum) != m.end())
			{
				len = max(len, i - m[sum]);
			}
			// sum is not found on the map
			else
			{
				m[sum] = i;
			}
		}
	}
	return len;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << largestSubarrayLen(arr, n);
}