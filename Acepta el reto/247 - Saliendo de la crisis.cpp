#include <iostream>

using namespace std;

const int  N = 100;

void resultado(int a[],int n){
	
	bool ordenado = true;
	int cont = 1;
	int elemento= a[0];
	
	while(ordenado && cont<n){
		if(elemento >= a[cont])
			ordenado=false;
		else elemento = a[cont];
		cont++;
	}
	
	
	
	if(ordenado)
		cout<<"SI"<<endl;
	else cout<<"NO"<<endl;
	
}

int main() {
	
	int n,a[N];
	
	cin>>n;
	
	while(n != 0){
		for(int i = 0; i < n; i++)
			cin>>a[i];
		resultado(a,n);
		
		cin>>n;
	}
	
	
	return 0;
}
