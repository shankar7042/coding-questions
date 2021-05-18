#include<bits/stdc++.h>
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

// O(n^2) Solution
// int maxProfit(vector<int>& prices)
// {
// 	int profit = 0;
// 	for (int i = 0; i < prices.size() - 1; i++)
// 	{
// 		for (int j = i + 1; j < prices.size(); j++)
// 		{
// 			if (prices[i] < prices[j])
// 			{
// 				profit = max(profit, prices[j] - prices[i]);
// 			}
// 		}
// 	}
// 	return profit;
// }

// O(n) Solution better
int maxProfit(vector<int>& prices)
{
	int profit = 0;
	int minimum = INT_MAX;
	for (int i = 0; i < prices.size(); i++)
	{
		minimum = min(minimum, prices[i]);
		profit = max(profit, prices[i] - minimum);
	}
	return profit;
}

int main()
{
	int size;
	cin >> size;
	vector<int> v;
	v.reserve(size);
	inputVector(v, size);
	printVector(v);
	cout << maxProfit(v);
	return 0;
}