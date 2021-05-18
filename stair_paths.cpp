#include<bits/stdc++.h>
using namespace std;

// All the paths
vector<string> printPathsRec(int n) {
	if (n == 0) {
		vector<string> v;
		v.push_back("");
		return v;
	} else if (n < 0) {
		vector<string> v;
		return v;
	}

	vector<string> n1 = printPathsRec(n - 1);
	vector<string> n2 = printPathsRec(n - 2);
	vector<string> n3 = printPathsRec(n - 3);
	vector<string> ans;

	for (auto &i : n1) {
		ans.push_back("1" + i);
	}
	for (auto &i : n2) {
		ans.push_back("2" + i);
	}
	for (auto &i : n3) {
		ans.push_back("3" + i);
	}
	return ans;
}

int countPathsRec(int n) {
	if (n == 0)
		return 1;
	else if (n < 0)
		return 0;

	int n1 = countPathsRec(n - 1);
	int n2 = countPathsRec(n - 2);
	int n3 = countPathsRec(n - 3);

	int ans = n1 + n2 + n3;
	return ans;
}

int countPathsMem(int n, vector<int> &dp) {
	if (n == 0)
		return 1;
	else if (n < 0)
		return 0;

	if (dp[n] > 0) {
		return dp[n];
	}

	int n1 = countPathsMem(n - 1, dp);
	int n2 = countPathsMem(n - 2, dp);
	int n3 = countPathsMem(n - 3, dp);

	int ans = n1 + n2 + n3;
	dp[n] = ans;
	return ans;
}

int countPathsTab(int n) {
	int dp[n + 1];
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dp[i] = dp[i - 1];
		} else if (i == 2) {
			dp[i] = dp[i - 1] + dp[i - 2];
		} else {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	// vector<string> v = printPathsRec(n);
	// for (auto &i : v) {
	// 	cout << i << " ";
	// }
	// cout << "\n";
	// int totalPaths = countPathsRec(n);

	// vector<int> v(n + 1);
	int totalPaths = countPathsTab(n);
	cout << totalPaths << "\n";
}