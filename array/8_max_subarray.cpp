#include<bits/stdc++.h>
using namespace std;


// O(n^3) Solution not good
int maxsubarray(vector<int> v)
{
	int sum, maxsum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j < v.size(); j++)
		{
			sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += v[k];
			}
			maxsum = max(sum, maxsum);
		}
	}
	return maxsum;
}

// O(n^2) A little better than the first one
int maxsubarray2(vector<int> v)
{
	int sum, maxsum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum = 0;
		for (int j = i; j < v.size(); j++)
		{
			sum += v[j];
		}
		maxsum = max(sum, maxsum);
	}
	return maxsum;
}

int main()
{
	vector<int> vect;
	int size;
	cin >> size;
	int num;
	for (int  i = 0; i < size; i++)
	{
		cin >> num;
		vect.push_back(num);
	}

	for (int  i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl << "Maximum subarray sum is: " << maxsubarray2(vect) << endl;
	return 0;
}