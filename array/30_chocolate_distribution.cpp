#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		int m;
		cin >> m;

		sort(arr, arr + n);
		int a = 0, b = m - 1, x = INT_MAX;
		while (b < n)
		{
			x = min(x, arr[b++] - arr[a++]);
		}
		cout << x << endl;
	}
}