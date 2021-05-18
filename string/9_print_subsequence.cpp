#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string s, string ans) {
	if (s.length() == 0) {
		cout << ans << " ";
		return;
	}

	string curr = s.substr(0, 1);
	string prev = s.substr(1);

	printSubsequence(prev, ans + "");
	printSubsequence(prev, ans + curr);

}

int main() {
	printSubsequence("aabc", "");
}