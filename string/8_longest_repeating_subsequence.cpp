#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
	int n1 = s1.length(), n2 = s2.length();
	int table[n1 + 1][n2 + 1];

	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			if (i == 0 || j == 0) {
				table[i][j] = 0;
			}
			else if (s1[i - 1] == s2[j - 1]) {
				table[i][j] = 1 + table[i - 1][j - 1];
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	return table[n1][n2];
}

int LongestRepeatingSubsequence(string str) {
	int n = str.length();
	int table[n + 1][n + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				table[i][j] = 0;
			}
			else if (str[i - 1] == str[j - 1] && i != j) {
				table[i][j] = 1 + table[i - 1][j - 1];
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	return table[n][n];
}

int main() {
	cout << LongestRepeatingSubsequence("AABEBCDD");
}