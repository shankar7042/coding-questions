#include <bits/stdc++.h>
using namespace std;

void printDuplicates(string s) {
	unordered_map<char, int> mp;

	for (auto &i : s) {
		mp[i]++;
	}

	for (auto &i : mp) {
		if (i.second > 1) {
			cout << i.first << " repeating " << i.second << " times\n";
		}
	}
}

int main() {
	printDuplicates("geeksforgeeks");
}