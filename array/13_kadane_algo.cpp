#include<bits/stdc++.h>
using namespace std;

// Kadane's algo to find maximun sum subarray
int maxsubarray(vector<int> &v)
{
	int sum = 0, maxsum = v[0];
	for (auto num : v)
	{
		sum += num;
		if (sum < 0)
		{
			sum = 0;
		}
		else if (sum > maxsum)
		{
			maxsum = sum;
		}
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
	cout << endl << "Maximum subarray sum is: " << maxsubarray(vect) << endl;
	return 0;
}