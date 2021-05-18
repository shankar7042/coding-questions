#include <bits/stdc++.h>
using namespace std;

bool isShuffle(string s1, string s2, string s) {
	if (s1.size() + s2.size() != s.size())
		return false;

	int i = 0, j = 0, k = 0;
	while (i < s1.size() && j < s2.size()) {
		if (s1[i] == s[k])
			i++;
		else if (s2[j] == s[k])
			j++;
		else
			return false;
		k++;
	}

	while (i < s1.size()) {
		if (s1[i] == s[k]) {
			i++;
			k++;
		} else {
			return false;
		}
	}

	while (j < s2.size()) {
		if (s2[j] == s[k]) {
			j++;
			k++;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << isShuffle(s1, s2, s3);
}