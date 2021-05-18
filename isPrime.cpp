#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n; cin >> n;
	bool ans = isPrime(n);
	if (ans) {
		cout << n << " is a Prime number\n";
	} else {
		cout << n << " is not a Prime number\n";
	}
}