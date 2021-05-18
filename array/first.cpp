#include<iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if(z < x || y <= z && z == 1) 
		if(z && y) 
			y = 1;
		else
			x = 1;

	cout << x << " " <<  y << " " << z;
	return 0;
}