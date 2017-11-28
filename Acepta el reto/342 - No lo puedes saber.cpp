#include <iostream>

using namespace std;

bool sol(int ini,int fin,int n,int k, int dummy, int a[]){
	if(ini==fin)
		return true;
	if(dummy == k)
		return false;
	if( a[dummy] >= ini &&  a[dummy] <= fin) 
		if(n >= a[dummy] )
			ini = a[dummy];
		else if(n < a[dummy])
			fin = a[dummy]-1;
	
	return sol(ini,fin,n,k,dummy+1,a);
	
}

int main(){
	int ini,fin,n;
	int k,dummy,a[250000];
	
	while(cin>> ini >> fin >> n && (ini !=0 && fin !=0 && n !=0)){
		cin >> k;
		for(int i = 0; i < k; ++i)
			cin>>a[i];
		
		dummy = 0;
		
		if(sol(ini,fin,n,k,dummy,a))
			cout << "LO SABE" <<endl;
		else cout << "NO LO SABE" <<endl;
	}
	
	return 0;
}
