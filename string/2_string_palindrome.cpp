#include <bits/stdc++.h>
using namespace std;

int isPlaindrome(string s) {
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s[left] != s[right])
			return false;
		left++;
		right--;
	}
	return true;
}

int main() {
	// vector<char> v = {'h', 'e', 'l', 'l', 'o'};
	// for (auto &i : v) {
	// 	cout << i << " ";
	// }
	// cout << "\n";
	// reverseString(v);
	// for (auto &i : v) {
	// 	cout << i << " ";
	// }
	// cout << "\n";
	cout << isPlaindrome("shankar");
	cout << isPlaindrome("abbbbba");
}