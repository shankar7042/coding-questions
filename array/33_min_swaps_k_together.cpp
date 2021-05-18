#include<bits/stdc++.h>
using namespace std;

// Sliding Window technique
int minSwap(int *arr, int n, int k)
{
	int good = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] <= k)
			good++;
	int bad = 0;
	for (int i = 0; i < good; i++)
		if (arr[i] > k)
			bad++;
	int ms = bad;
	for (int i = 0, j = good; j < n; i++, j++)
	{
		if (arr[i] > k)
			bad--;
		if (arr[j] > k)
			bad++;
		ms = min(ms, bad);
	}
	return ms;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int k;
	cin >> k;
	cout << minSwap(arr, n, k);
}