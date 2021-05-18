#include<bits/stdc++.h>
using namespace std;

// O(n*m)
// int rowWithMax1s(vector<vector<int> > &arr, int n, int m)
// {
// 	int result = 0;
// 	int row = -1;
// 	for (int i = 0; i < n; i++)
// 	{
// 		int count = 0;
// 		for (int j = 0; j < m; j++)
// 		{
// 			if (arr[i][j] == 1)
// 				count++;
// 		}
// 		if (count > result)
// 		{
// 			result = count;
// 			row = i;
// 		}
// 	}
// 	if (result == 0)
// 		return -1;
// 	else
// 		return row;
// }

int firstOne(vector<int> &arr, int low, int high)
{
	if (low <= high)
	{
		int mid = low + (high - low) / 2;

		if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
			return mid;
		else if (arr[mid] == 0)
			return firstOne(arr, mid + 1, high);
		else
			return firstOne(arr, low, mid - 1);
	}
	return -1;
}

int rowWithMax1s(vector<vector<int> > &arr, int n, int m)
{
	int max_row_index = -1, max = -1;
	int index, count;
	for (int i = 0; i < n; i++)
	{
		index = firstOne(arr[i], 0, m - 1);
		count = m - index;
		if (index != -1 && count > max)
		{
			max = count;
			max_row_index = i;
		}
	}
	return max_row_index;
}

int main()
{
	int r, c;
	cin >> r >> c;
	vector<vector<int>> vect(r, vector<int>(c));
	int x;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> vect[i][j];
		}
	}
	for (auto v : vect)
	{
		for (auto num : v)
		{
			cout << num << " ";
		}
		cout << endl;
	}
	cout << rowWithMax1s(vect, r, c);
}