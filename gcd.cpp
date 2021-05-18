#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

// int gcd_rec(int a, int b) {
// 	if (b == 0)
// 		return a;
// 	return gcd_rec(b, a % b);
// }

int gcd_rec(int a, int b) {
	return b == 0 ? a : gcd_rec(b, a % b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int ans = gcd_rec(a, b);
		cout << "GCD(" << a << ", " << b << ") = " << ans << "\n";
	}
}