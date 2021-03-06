#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
	int left = 0, right = s.size() - 1;
	while (left < right) {
		swap(s[left], s[right]);
		left++;
		right--;
	}
}

int main() {
	vector<char> v = {'h', 'e', 'l', 'l', 'o'};
	for (auto &i : v) {
		cout << i << " ";
	}
	cout << "\n";
	reverseString(v);
	for (auto &i : v) {
		cout << i << " ";
	}
	cout << "\n";
}
