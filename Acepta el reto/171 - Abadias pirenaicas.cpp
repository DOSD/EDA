#include <iostream>

using namespace std;

const int N = 100000;

int resultado(int a[], int n) {
	int sum = 1;
	int i, temp = a[n-1];
	bool imposible;
	for (i = n-2;i >= 0; i--) {
		if (a[i] > temp) {
			sum++;
			temp = a[i];
		}
	}
	return sum;
}

int main() {
	
	int n, i, a[N];
	cin >> n;
	
	while (n != 0) {
		for (i = 0;i<n;i++)
			cin >> a[i];
		cout << resultado(a, n) << "\n";
		cin >> n;
		
	}
	
	return 0;
}
