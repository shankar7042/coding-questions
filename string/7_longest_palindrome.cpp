#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r) {
	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}
	return true;
}

// O(n^3) ans S(1)
// string longestPalindrome(string s) {
// 	int maxLength = INT_MIN;
// 	string ans;
// 	int l, r;
// 	for (int i = 0; i < s.length(); ++i) {
// 		for (int j = i; j < s.length(); ++j) {
// 			if (isPalindrome(s, i, j)) {
// 				if ((j - i + 1) > maxLength) {
// 					maxLength = j - i + 1;
// 					l = i;
// 					r = j;
// 				}
// 			}
// 		}
// 	}
// 	for (int a = l; a <= r; a++) {
// 		ans.push_back(s[a]);
// 	}
// 	return ans;
// }

string longestPalindrome(string str) {
	int n = str.length();
	bool table[n][n];

	int maxLength = 1;
	int start;
	// For length = 1 every substring is palindrome
	for (int i = 0; i < n; i++)
		table[i][i] = true;

	// for length = 2 substring is palindrome iff first letter is same
	// as the second letter
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	// for string length greater than or equal to 3;
	for (int k = 3; k <= n; ++k) {
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i) {
			// Get the ending index of substring from
			// starting index i and length k
			int j = i + k - 1;

			// checking for sub-string from ith index to
			// jth index iff str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}

	string ans;
	for (int a = start; a <= start + maxLength - 1; a++) {
		ans.push_back(str[a]);
	}
	return ans;
}

int main() {
	int t; cin >> t;
	string s;
	while (t--) {
		cin >> s;
		cout << longestPalindrome(s) << "\n";
	}
}