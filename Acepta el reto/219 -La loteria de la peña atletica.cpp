#include <iostream>

using namespace std;

const int  N = 10000;


//{Pre: 0 <= n <= 10000}
int resultado(int a[],int n){
	int cont = 0;
	
	for(int i = 0; i  < n; i++)
		if(a[i]%2 == 0)
			cont++;
	
	return cont;
}

// {Post: cont = # i: 0 <= i < n : a[i]mod2 = 0}

int main() {
	
	int n,m,a[N];
	
	cin>>n;
	
	for(int i = 1; i <= n; i++){
		cin >> m;
		for(int i = 0; i < m; i++)
			cin>>a[i];
		
		cout << resultado(a,m)<<endl;
	}
	
	
	return 0;
}
