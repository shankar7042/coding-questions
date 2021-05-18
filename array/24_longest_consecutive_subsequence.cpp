#include<bits/stdc++.h>
using namespace std;


int findLongestConseqSubseq(int arr[], int n)
{
	sort(arr, arr + n);
	int result = 1, currentLen = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			if (arr[i] + 1 == arr[i + 1])
			{
				currentLen++;
			}
			else
			{
				currentLen = 1;
			}
			result = max(result, currentLen);
		}
	}
	return result;
}

int longestConsecutive(vector<int>& arr)
{
	set<int> hashSet;
	for (int num : arr)
		hashSet.insert(num);

	int result = 0;

	for (int num : arr)
	{
		if (!hashSet.count(num - 1))
		{
			int currentNum = num;
			int currentLen = 1;

			while (hashSet.count(currentNum + 1))
			{
				currentNum++;
				currentLen++;
			}

			result = max(result, currentLen);
		}
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
	vector<int> vect(arr, arr + n);
	// sort(arr, arr + n);
	// for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << findLongestConseqSubseq(arr, n);
	cout << endl;
	cout << longestConsecutive(vect);
}