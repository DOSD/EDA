#include <iostream>

using namespace std;

const int  N = 10001;


//{Pre: 0 < n <= longitud(v)}

int num_Picos(int a[], int n){
	int pico = 0;
	for(int i = 1; i < n-1; ++i)
		if(a[i] > a[i-1] && a[i] > a[i+1])
			pico++;

	return pico;
}

// {Post: ret = # i: 1 <= i < n-1: a[i] > a[i-1] ^ a[i] > a[i+1]   }


//{Pre: 0 < n <= longitud(v)}

int num_Valles(int a[], int n){
	int valle = 0;
	for(int i = 1; i < n-1; ++i)
		if(a[i] < a[i-1] && a[i] < a[i+1])
			valle++;

	return valle;
}
	// {Post: ret = # i: 1 <= i < n-1: a[i] < a[i-1] ^ a[i] < a[i+1]   }

void resultado(int a[],int n){
	int pico, valle;

	pico = num_Picos(a,n);
	valle = num_Valles(a,n);

	cout<<pico<<" "<< valle<<endl;
}

// {Post: ret = # i: 1 <= i < n-1: a[i] > a[i-1] ^ a[i] > a[i+1]   }

int main() {

	int n,m,a[N];

	cin>>n;

	for(int i = 1; i <= n; i++){
		cin >> m;
		
		for(int i = 0; i < m; i++)
			cin>>a[i];
		
		resultado(a,m);
	}

	
	return 0;
}