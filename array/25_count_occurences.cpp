#include<bits/stdc++.h>
using namespace std;

void moreThanNdK(int arr[], int n, int k)
{
	int x = n / k;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;
	for (auto item : mp)
		if (item.second > x)
			cout << item.first << " ";
}

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
	moreThanNdK(arr, n, k);
}