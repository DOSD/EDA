#include <iostream>

using namespace std;

const int N = 25000;

void ordenar(long int lista[],int TAM){
	long int temp;
	int i,j;
	for (i=1; i<TAM; i++){
		temp = lista[i];
		j = i - 1;
		while ( (lista[j] > temp) && (j >= 0) ){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1] = temp;
	}
}

int resuelve(long int a[],int n){
	ordenar(a,n);
	int i = 1, m=a[0], fm=1, fa=1;
	
	while(i<n){
		if(a[i]==a[i-1]){
			++fa;
			if(fm<fa){
				fm=fa;
				m=a[i];
			}
			
			
		}
		else fa=1;
		i++;
	}
	return m;
}


int main(){
	int n;
	long int a[N];
	
	cin>>n;
	
	while(n != 0 && std::cin){
		for(int i=0;i<n;++i)
			cin>>a[i];
		
		cout<<resuelve(a,n)<<endl;
		cin>>n;
	}
	return 0;
}
