#include <iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n && n != 0){
		int s2 = 0;
		long long int v[100000];
		int i = 0;
		while (i<n) {
			int x; cin >> x;
			v[i] = x;
			s2 += x;
			++i;
		}
		
		int s1 = 0;
		int cnt = 0;
		
		if (s1 == s2) cnt++;
		for (int i = 0; i < n; i++) {
			s1 += v[i];
			s2 -= v[i];
			if (s1 == s2) cnt++;
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
