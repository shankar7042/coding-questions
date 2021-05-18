#include <bits/stdc++.h>
using namespace std;

// int uniquePaths(int a, int b) {
// 	if (a == 1 || b == 1)
// 		return 1;
// 	return uniquePaths(a, b - 1) + uniquePaths(a - 1, b);
// }

// int uniquePaths(int a, int b) {
// 	int dp[a][b];
// 	for (int i = 0; i < a; i++) {
// 		for (int j = 0; j < b; j++) {
// 			if (i == 0 || j == 0)
// 				dp[i][j] = 1;
// 			else
// 				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
// 		}
// 	}
// 	return dp[a - 1][b - 1];
// }

int uniquePaths(int a, int b) {
	int N = a + b - 2;
	int r = a - 1;
	double res = 1;
	for (int i = 1; i <= r; i++)
		res = res * (N - r + i) / i;
	return (int)res;
}

int sqrt(int a) {
	int low = 1;
	int high = a;
	int ans = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		int sqr = mid * mid;
		if (sqr == a)
			return mid;
		else if (sqr < a) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return ans;
}

int solve(vector<int> &a, int b) {
	int low = 0;
	int high = a.size() - 1;
	int mid = low + (high - low) / 2;
	int bitonic = -1;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
			bitonic = mid;
			break;
		}
		else if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
			low = mid + 1;
		else if (a[mid] < a[mid - 1] && a[mid] > a[mid + 1])
			high = mid - 1;
	}

	if (a[bitonic] == b)
		return bitonic;

	int llow = 0;
	int lhigh = bitonic - 1;
	int pos = -1;
	while (llow <= lhigh) {
		int lmid = llow + (lhigh - llow) / 2;
		if (a[lmid] == b) {
			pos = lmid;
			break;
		}
		else if (a[lmid] < b)
			llow = lmid + 1;
		else
			lhigh = lmid - 1;
	}

	if (pos != -1)
		return pos;

	int rlow = bitonic + 1;
	int rhigh = a.size() - 1;
	int rpos = -1;
	while (rlow <= rhigh) {
		int rmid = rlow + (rhigh - rlow) / 2;
		if (a[rmid] == b) {
			rpos = rmid;
			break;
		}
		else if (a[rmid] > b)
			rlow = rmid + 1;
		else
			rhigh = rmid - 1;
	}
	if (rpos != 1)
		return rpos;
	else
		return -1;
}


int main() {
	vector<int> v1 = {3, 9, 10, 20, 17, 5, 1};
	int b1 = 20;
	vector<int> v2 = {5, 6, 7, 8, 9, 10, 3, 2, 1};
	int b2 = 30;
	cout << solve(v1, b1) << "\n";
	cout << solve(v2, b2) << "\n";
}
