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
