#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n + 1];

		for (int i = 1; i <= n; i++)
			cin >> a[i];

		int k;
		cin >> k;
		int x = 1, y = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i] + 1;
			if (sum > k) {
				y = i - 1;
				sum = 0;
				cout << x << " " << y << " ";
				x = i;
				y = i;
			}
		}
		cout << x << " " << y << "\n";
	}
}