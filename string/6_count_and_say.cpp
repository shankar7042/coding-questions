#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
	if (n == 1 )
		return "1";
	if (n == 2)
		return "11";
	else {
		string prev = countAndSay(n - 1);
		prev.push_back('&');
		string current;
		int count = 1;
		for (int i = 1; i < prev.size(); i++) {
			if (prev[i] == prev[i - 1]) {
				count++;
			} else {
				current += to_string(count);
				current.push_back(prev[i - 1]);
				count = 1;
			}
		}
		return current;
	}
}

// string countAndSay(int n) {
// if (n == 1 )
// 	return "1";
// if (n == 2)
// 	return "11";
// else {
// 	string s = "11";
// 	for (int i = 3; i <= n; i++) {
// 		string t = "";
// 		s.push_back('&');
// 		int c = 1;
// 		for (int j = 1; j < s.size(); j++) {
// 			if (s[j] != s[j - 1]) {
// 				t = t + to_string(c);
// 				t = t + s[j - 1];
// 				c = 1;
// 			} else {
// 				c++;
// 			}
// 		}
// 		s = t;
// 	}
// 	return s;
// }
// }

int main() {
	cout << countAndSay(20);
}