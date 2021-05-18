#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		int a[n + 1];
		int left[n + 1];
		int right[n + 1];
		int x = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		left[0] = right[n + 1] = 0;
		for (int i = 1; i <= n; i++) {
			left[i] = gcd(left[i - 1], a[i]);
		}
		for (int i = n; i >= 1; i--) {
			right[i] = gcd(right[i + 1], a[i]);
		}
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << gcd(left[l - 1], right[r + 1]) << "\n";
		}
	}
}