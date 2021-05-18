#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& arr, int a, int b)
{
	int low = 0, mid = 0, high = arr.size() - 1;

	while (mid <= high)
	{
		if (arr[mid] < a)
		{
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		}
		else if (arr[mid] > b)
		{
			swap(arr[mid], arr[high]);
			high--;
		}
		else
		{
			mid++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	vector<int> vect(arr, arr + n);
	threeWayPartition(vect, a, b);
	for (auto num : vect)
		cout << num << " ";
	cout << endl;
}