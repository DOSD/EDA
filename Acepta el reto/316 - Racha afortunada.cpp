#include <iostream>

using namespace std;

int main() {
	int t;
	
	cin >> t;
	while(t>0) {
		int n, ini = 1, fin = n, oini, ofin, osum = -10000, sum = -10000;
		int val;
		
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> val;
			if (val >= sum + val) ini = fin = i, sum = val;
			else fin++, sum += val;
			if (sum > osum) oini = ini, ofin = fin, osum = sum;
			else if (sum == osum && fin - ini < ofin - oini) oini = ini, ofin = fin;
		}
		
		cout<<oini<<" "<<ofin<<endl;
		t--;
	}
	
	return 0;
}
