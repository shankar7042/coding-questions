#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, k; cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k > 0) {
			int x = n / k;
			cout << n - (x * k) << "\n";
		} else {
			cout << n << "\n";
		}
	}
}
