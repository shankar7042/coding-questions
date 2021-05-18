#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> m >> n;
		int arr1[m], arr2[n];
		for (int i = 0; i < m; i++) cin >> arr1[i];
		for (int i = 0; i < n; i++) cin >> arr2[i];
		bool flag = true;
		if (n > m)
			cout << "No" << endl;
		else
		{
			for (int i = 0; i < n; i++)
			{
				int j;
				for (j = 0; j < m; j++)
				{
					if (arr2[i] == arr1[j])
						break;
				}
				if (j == m)
				{
					cout << "No" << endl;
					flag = false;
					break;
				}
			}
			if (flag)
				cout << "Yes" << endl;
		}
	}
}