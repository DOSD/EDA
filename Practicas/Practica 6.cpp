#include<iostream>

using namespace std;

bool estaBalanceado(int &peso){
	int p1,d1,p2,d2,peso1,peso2;
	bool ret = true;
	cin>> p1 >> d1 >> p2 >> d2;
	peso =0;
	if(p1 != 0 && p2 != 0){
		peso = (p1+p2);
		return (p1 * d1 == p2 * d2);
	}

	if(p1 == 0)
		if(!estaBalanceado(peso1))
			ret = false;
	
	if(p2 == 0)
		if(!estaBalanceado(peso2))
			ret = false;
	if(ret){
		if(p1 == 0 && p2 != 0){
			peso = peso1 +p2;
			return (peso1* d1 == p2 * d2);
		}
		else if(p1 != 0 && p2 == 0){
			peso = peso2 +p1;
			return (p1*d1 == peso2 * d2);
		}
		else{
			peso = peso1 + peso2; 
			return peso1*d1 == peso2 *d2;
		}
	}
	else return false;
}
//104
int main(){

	int n,i = 0,dummy;
	cin>>n;
	while(i < n){
		dummy = 0;
		if(estaBalanceado(dummy))
			cout<<"SI"<<endl;
		else cout<<"NO"<<endl;
		i++;
	}

	return 0;
}




