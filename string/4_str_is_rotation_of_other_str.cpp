#include <bits/stdc++.h>
using namespace std;


int main() {
	string s1 = "ABCD";
	string s2 = "DABC";

	string temp = s1 + s1;
	if (s1.length() != s2.length())
		cout << "No";
	else if (temp.find(s2) != string::npos) {
		cout << "Yes";
	}
}