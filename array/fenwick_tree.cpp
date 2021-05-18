// Fenwick Tree or Binary Index tree

#include<bits/stdc++.h>
using namespace std;

// Note: the indexing in fenwick tree is from 1.

// In bit arr each index value is the sum of j + 1 -> i
// where i is the index
// and j is the value after removing last set bit in the i;
// Eg: Index(i) = 12 binary representation(i = 12) = 1100
// then (i & -i) will give us the last set bit of i = 0100
// after removing last set bit of i(12) = 1100 - 0100 = 1000(8)
// then it means that at index 12 the value store is the sum of 8 + 1 = 9 to 12

const int N = 1e5 + 10;
int bit[N];

// this method is used to create the fenwick tree
// method to add the value(x) at index i
void update(int i, int x)
{
	for (; i < N; i += (i & -i))
		bit[i] += x;
}

// this method return the sum of 1 to i i.e. if i = 10 then sum(10) is return sum of 1 -> 10
int sum(int i)
{
	int ans = 0;
	for (; i > 0; i -= (i & -i))
		ans += bit[i];
	return ans;
}

int sum_range(int left, int right)
{
	return sum(right) - sum(left - 1);
}

int main()
{
	int size;
	cin >> size;
	int arr[size + 10];

	// create a fenwick tree or Binary index tree
	for (int i = 1; i <= size; i++)
	{
		cin >> arr[i];
		update(i, arr[i]);
	}

	for (int i = 1; i <= size; i++)
		cout << sum(i) << " ";
	cout << endl;

	// Print the sum of index 2 to 4
	cout << sum_range(2, 4);
	return 0;
}