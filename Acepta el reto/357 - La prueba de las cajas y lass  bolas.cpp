#include <iostream>

using namespace std;

int soluciona(long long n) {
	if (n == 1)
		return 1; 
	
	return 1 + soluciona(n / 2);
}

int main() {
	long long n;
	
	while (cin >> n)
		cout << soluciona(n) << endl;
	return 0;
}
