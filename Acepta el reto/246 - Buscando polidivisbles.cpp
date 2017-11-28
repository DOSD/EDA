#include <iostream>

using namespace std;

int NumDigitos(long long int n){
	int ret = 1;
	long long num=n;

	while(num/10 != 0){
		ret++;
		num= num/10;
	}
	return ret;
}

void escribirPolidivisibles(long long int n,int digitos,int md){
	if(digitos > md)
		return;

	cout << n <<endl;

	for(int i = 0; i < 10; ++i){
		long long nuevaRaiz = n*10 +i;
		if(nuevaRaiz % (digitos+1) == 0)
			escribirPolidivisibles(nuevaRaiz,digitos +1,md);
	}
	
}

void resuelve(long long int n,int m){
	int digitos = NumDigitos(n);

	escribirPolidivisibles(n,digitos,m);
		

}

int main(){
	long long int n;
	int m;

	while(cin>>n){
		cin>>m;
		resuelve(n,m);
		cout<<"---"<<endl;
	}

	return 0;
}



