#include<iostream>

using namespace std;

const int k = 31543;

int sol(int x, int n) {
	if (n == 0) 
		return 1;
	
	if (n % 2 == 0) {
		int x1 = sol(x, n/2);
		return (x1 * x1) % k;
	} else {
		int x1 = sol(x, (n-1)/2);
		return (((x1 * x1) % k) * (x % k)) % k;
	}
}

int main() {
	int x, n;
	while (cin >> x >> n && !(x == 0 && n == 0)) {
		cout << sol(x, n) << endl;
	}
	
	return 0;
}
