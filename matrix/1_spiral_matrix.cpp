#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > &matrix, int r, int c)
{
	int top = 0, down = r - 1, left = 0, right = c - 1;
	int dir = 0;
	vector<int> result;
	while (top <= down && left <= right)
	{
		if (dir == 0)
		{
			for (int i = left; i <= right; i++)
				result.push_back(matrix[top][i]);
			top++;
		}
		else if (dir == 1)
		{
			for (int i = top; i <= down; i++)
				result.push_back(matrix[i][right]);
			right--;
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
				result.push_back(matrix[down][i]);
			down--;
		}
		else if (dir == 3)
		{
			for (int i = down; i >= top; i--)
				result.push_back(matrix[i][left]);
			left++;
		}
		dir = (dir + 1) % 4;
	}
	return result;
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
			cin >> x;
			vect[i][j] = x;
		}
	}

	// for (auto v : vect)
	// {
	// 	for (auto num : v)
	// 	{
	// 		cout << num << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<int> result;
	result = spirallyTraverse(vect, r, c);
	for (auto num : result)
		cout << num << " ";
	cout << endl;
}