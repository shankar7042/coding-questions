#include<bits/stdc++.h>
using namespace std;

// O(n^2) with S(1) but with sorting and two pointer approach
// bool find3Numbers(int arr[], int n, int X)
// {
// 	int l, r;
// 	sort(arr, arr + n);

// 	for (int i = 0; i < n - 2; i++)
// 	{
// 		l = i + 1;
// 		r = n - 1;
// 		while (l < r)
// 		{
// 			if (arr[i] + arr[l] + arr[r] == X)
// 			{
// 				cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
// 				return true;
// 			}
// 			else if (arr[i] + arr[l] + arr[r] < X)
// 				l++;
// 			else
// 				r--;
// 		}
// 	}
// 	return false;
// }

// O(n^2) with S(n) with hash map
bool find3Numbers(int arr[], int n, int X)
{
	for (int i = 0; i < n - 2; i++)
	{
		unordered_set<int> m;
		int curr_sum = X - arr[i];
		for (int j = i + 1; j < n; j++)
		{
			if (m.find(curr_sum - arr[j]) != m.end())
			{
				cout << arr[i] << " " << arr[j] << " " << curr_sum - arr[j] << endl;
				return true;
			}
			else
			{
				m.insert(arr[j]);
			}
		}
	}
	return false;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << find3Numbers(arr, n, k);
}