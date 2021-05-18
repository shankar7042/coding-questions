#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> mem;

int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	if (n == 0)
		return 0;

	vector<int> left(n), right(n);
	int leftMin = prices[0];
	for (int i = 1; i < n; i++)
	{
		left[i] = max(left[i - 1], prices[i] - leftMin);
		leftMin = min(leftMin, prices[i]);
	}
	int rightMax = prices[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		right[i] = max(right[i + 1], rightMax - prices[i]);
		rightMax = max(rightMax, prices[i]);
	}
	int profit = right[0];
	for (int i = 1; i < n; i++)
	{
		profit = max(profit, left[i - 1] + right[i]);
	}
	return profit;
}

int recursion(vector<int> &prices, int pos, int t, bool bought)
{
	if (pos >= prices.size() || t == 0)
		return 0;
	if (mem[bought][t][pos] != -1)
		return mem[bought][t][pos];

	int result = recursion(prices, pos + 1, t, bought);
	if (bought)
		result = max(result, recursion(prices, pos + 1, t - 1, false) + prices[pos]);
	else
		result = max(result, recursion(prices, pos + 1, t, true) - prices[pos]);

	mem[bought][t][pos] = result;
	return result;
}

int maxProfit2(vector<int> &prices)
{
	mem.resize(2, vector<vector<int>>(3, vector<int>(prices.size(), -1)));
	int result = recursion(prices, 0, 2, false);
	return result;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> prices(arr, arr + n);
	for (auto num : prices)
		cout << num << " ";
	cout << endl;
	cout << maxProfit2(prices);
}