#include <iostream>

using namespace std;

const int N = 100000;

void resultado(long long int a[], int n){
	long long int sum = 0;
	long long int acum = 0; 
	for (int i=0; i<n; i++) {
		sum += acum * a[i];
		acum += a[i];
	}
	cout<< sum<<"\n";
}

int main(){
	
	int n,i;
	long long int a[N];
	cin>>n;
	
	while(n != 0){
		for(i=0;i<n;i++)
			cin>>a[i];
		resultado(a,n);
		cin>>n;
		
	}
	
	return 0;
}
