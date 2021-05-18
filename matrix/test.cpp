#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
	vector<pair<int, int>> X;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			if (A[i][j] == 0)
				X.push_back(make_pair(i, j));
		}
	}
	for (auto &p : X) {
		for (int i = 0; i < A.size(); i++) {
			A[p.first][i] = 0;
		}
		for (int i = 0; i < A[0].size(); i++) {
			A[i][p.second] = 0;
		}
	}
}

string findDigitsInBinary(int A) {
	int temp = A;
	string result;
	while (temp > 0) {
		result.push_back((char)('0' + (temp % 2)));
		temp /= 2;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	// int n , m;
	// cin >> n >> m;
	// vector<vector<int>> v(n, vector<int>(m));
	// for (auto &i : v)
	// 	for (auto &j : i)
	// 		cin >> j;
	// setZeroes(v);
	// for (auto &i : v) {
	// 	for (auto &j : i)
	// 		cout << j << " ";
	// 	cout << "\n";
	// }
	int n; cin >> n;
	string r;
	r = findDigitsInBinary(n);
	cout << r;
}