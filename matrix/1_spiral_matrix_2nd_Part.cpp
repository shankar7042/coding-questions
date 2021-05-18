#include<bits/stdc++.h>
using namespace std;

pair < vector<vector<int>>, int> generateMatrix(int A) {
	int top = 0, down = A - 1, left = 0, right = A - 1;
	vector<vector<int>> result(A, vector<int>(A));
	int counter = 1;
	while (top <= down && left <= right) {
		for (int i = left; i <= right; i++)
			result[top][i] = counter++;
		top++;
		for (int i = top; i <= down; i++)
			result[i][right] = counter++;
		right--;
		for (int i = right; i >= left; i--)
			result[down][i] = counter++;
		down--;
		for (int i = down; i >= top; i--)
			result[i][left] = counter++;
		left++;
	}
	pair<vector<vector<int>>, int> p;
	p.first = result;
	p.second = counter;
	return p;
}

int main() {
	int n;
	cin >> n;
	pair < vector<vector<int>>, int> result;
	result = generateMatrix(n);
	// string s = to_string(result.second);
	// int no_of_digits = s.size();
	for (auto v : result.first) {
		for (auto num : v) {
			if (result.second < 100) {
				if (num < 10) {
					cout << " " << num << " ";
				}
				else {
					cout << num << " ";
				}
			}
			else if (result.second >= 100 && result.second < 1000) {
				if (num < 10) {
					cout << "  " << num << " ";
				}
				else if (num >= 10 && num < 100) {
					cout << " " << num << " ";
				}
				else {
					cout << num << " ";
				}
			}
		}
		cout << endl;
	}
}