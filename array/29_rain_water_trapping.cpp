#include<bits/stdc++.h>
using namespace std;

// int trappingWater(int arr[], int n)
// {
// 	int pre[n], suff[n];
// 	int x = arr[0];
// 	for (int i = 0; i < n; i++)
// 	{
// 		x = max(x, arr[i]);
// 		pre[i] = x;
// 	}
// 	x = arr[n - 1];
// 	for (int i = n - 1; i >= 0; i--)
// 	{
// 		x = max(x, arr[i]);
// 		suff[i] = x;
// 	}
// 	int ans = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		ans += min(pre[i], suff[i]) - arr[i];
// 	}
// 	return ans;
// }

// int trappingWater(vector<int> arr)
// {
// 	int n = arr.size();
// 	vector<int> pre(n), suff(n);
// 	int x = arr[0];
// 	for (int i = 0; i < n; i++)
// 	{
// 		x = max(x, arr[i]);
// 		pre[i] = x;
// 	}
// 	x = arr[n - 1];
// 	for (int i = n - 1; i >= 0; i--)
// 	{
// 		x = max(x, arr[i]);
// 		suff[i] = x;
// 	}
// 	int ans = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		ans += min(pre[i], suff[i]) - arr[i];
// 	}
// 	return ans;
// }

int trappingWater(vector<int> arr)
{
	int l = 0,
	    r = arr.size() - 1,
	    leftMax = 0,
	    rightMax = 0;

	int result = 0;
	while (l < r)
	{
		if (arr[l] <= arr[r])
		{
			if (arr[l] >= leftMax)
			{
				leftMax = arr[l];
			}
			else
			{
				result += leftMax - arr[l];
			}
			l++;
		}
		else
		{
			if (arr[r] >= rightMax)
			{
				rightMax = arr[r];
			}
			else
			{
				result += rightMax - arr[r];
			}
			r--;
		}
	}
	return result;
}


int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> vect(arr, arr + n);
	cout << trappingWater(vect);
}