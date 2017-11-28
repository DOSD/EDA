#include <iostream>

using namespace std;

long long int escribeSuma(long long int n){
	if(n<10){
		cout<<n;
		return n;
	}

	long long int resto = n%10;
	long long int aux=escribeSuma(n/10);
	cout<<" + "<<resto;
	return aux+resto;

}

int main (){
	long long int n;
	cin>>n;

	while(n>0){
		long long int aux=escribeSuma(n);
		cout<<" = "<<aux<<endl;
		cin>>n;
	}

	return 0;
}

/* 237


bool esPolidivisible(long long n, int &digitosDeN){
	if(n<10){
		digitosDeN = 1;
 		return true;
		
	}

	int nd;
	bool aux= esPolidivisible(n/10,nd);

	digitosDeN = 1+nd;
	return aux && (n % digitosDeN == 0 );

}


 /*
#include<iostream>

using namespace std;

bool esPolidivisible(long long n,int &digitosDeN){
	if(n<10){
		digitosDeN = 1;
 		return true;
		
	}

	int nd;
	bool aux= esPolidivisible(n/10,nd);

	digitosDeN = 1+nd;
	return aux && (n % digitosDeN == 0 );

}

int main(){
  long long int n;
  int dummy;
  
  
  while(cin>>n){
    if(esPolidivisible(n,dummy))
      cout<<"POLIDIVISIBLE"<<endl;
    else cout<<"NO POLIDIVISIBLE"<<endl;
    
    
  }
  
  return 0;
}
*/