#include<bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n)
{
	long long minValue = arr[0],
	          maxValue = arr[0],
	          product = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < 0)
			swap(minValue, maxValue);

		minValue = min((long long)arr[i], minValue * arr[i]);
		maxValue = max((long long)arr[i], maxValue * arr[i]);

		product = max(product, maxValue);
	}
	return product;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
	cout << maxProduct(arr, n) << endl;
}