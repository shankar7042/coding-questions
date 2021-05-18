#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> arr, int key)
{
	int n = arr.size();
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == key)
			return true;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return false;
}

// function if matrix is sorted row-wise and column-wise both
// bool searchMatrix(vector<vector<int>>& matrix, int target)
// {
//     int r = matrix.size();
//     int c = matrix[0].size();
//     int i = 0;
//     int j = c - 1;

//     while(i < r && j >= 0)
//     {
//         if(matrix[i][j] == target)
//             return true;
//         else if(matrix[i][j] < target)
//             i++;
//         else
//             j--;
//     }
//     return false;
// }

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.size() == 0)
		return false;

	int r = matrix.size();
	int c = matrix[0].size();

	int row = 0;
	for (int i = 0 ; i < r; i++)
		if (matrix[i][c - 1] == target)
			return true;
		else if (matrix[i][c - 1] < target)
			row++;
		else
			break;
	bool result = binarySearch(matrix[row], target);
	if (result)
		return true;
	else
		return false;
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
	int target;
	cin >> target;
	for (auto v : vect)
	{
		for (auto num : v)
		{
			cout << num << " ";
		}
		cout << endl;
	}
	cout << searchMatrix(vect, target);
}