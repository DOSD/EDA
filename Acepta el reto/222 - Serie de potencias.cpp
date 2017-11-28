#include <iostream>
#include <math.h>

using namespace std;

long long int resuelve(int x, int n){
	long long int ret =0;
	long long int pot = 1;
	int i=0;
	while(i<=n){
		pot = pow(x,i);
		ret += pot;
		i++;
	}

	return ret%1000007;

}


int main(){
	int x,n;
	

	while(cin>>x){
		cin>>n;
		cout<<resuelve(x,n)<<endl;
	}

	return 0;
}