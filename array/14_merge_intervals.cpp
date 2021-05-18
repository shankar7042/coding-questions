#include <bits/stdc++.h>
using namespace std;

void inputVector(vector<int> &vect, int size)
{
	int num;
	for (int i = 0; i < size; i++)
	{
		cin >> num;
		vect.push_back(num);
	}
}

void printVector(vector<int> &vect)
{
	for (auto item : vect)
	{
		cout << item << " ";
	}
	cout << endl;
}

void printVector2(vector<vector<int>> &vect)
{
	for (auto item : vect)
	{
		for (auto num : item)
			cout << num << " ";
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
	vector<vector<int>> result;
	if (intervals.size() == 0)
	{
		return result;
	}

	sort(intervals.begin(), intervals.end());
	vector<int> temp = intervals[0];

	for (auto it : intervals)
	{
		if (it[0] <= temp[1])
		{
			temp[1] = max(it[1], temp[1]);
		}
		else
		{
			result.push_back(temp);
			temp = it;
		}
	}
	result.push_back(temp);
	return result;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int size;
	cin >> size;
	vector<vector<int>> vect{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	printVector2(vect);
	vector<vector<int>> result = mergeIntervals(vect);
	printVector2(result);
	return 0;
}