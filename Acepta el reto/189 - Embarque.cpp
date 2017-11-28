#include <iostream>
#include <string>

using namespace std;

void reslueve(int a[], long long int &n, long long int emb) {
	long long int i = 0, c = 0;
	
	while (i<n) {
		if (a[i] != emb) {
			a[c] = a[i];
			c++;
		}
		i++;
	}
	n = c ;
}

int main() {
	long long int n, i, c, m;
	int* a = new int[1000000];
	string s;
	cin >> n;
	while (n != 0) {
		i = 0;
		while (i<n) {
			cin >> a[i];
			++i;
		}
		cin >> m;
		i = 0;
		while (i<m) {
			cin >> s;
			cin >> c;
			if (s == "CONSULTA") {
				cout << a[c - 1] << endl;
			}
			else {
				reslueve(a, n, c);
				cout << n  << endl;
			}
			i++;
		}
		cout << "*" << endl;
		cin >> n;
	}
	
	return 0;
}
