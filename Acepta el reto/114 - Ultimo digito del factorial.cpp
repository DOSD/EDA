#include <iostream>

using namespace std;

int resultado(int m){
	int resultado=1,i=1;
	while(i<=m && m<5){
		resultado *= i;
		resultado = resultado %10;
		i++;
	}
	
	if(m >= 5)
		resultado = 0;
	
	return resultado;
}

int main(){
	
	int n,i,m;
	cin>>n;
	
	for(i=0;i<n;i++){
		cin>>m;
		cout<<resultado(m)<<"\n";
	}
	
	return 0;
}
