#include <iostream>

using namespace std;

long long longitud(long long n){
	if(n == 1)
		return n*4;

	return (longitud(n/2)*4 + n*4);
}

int main(){

	long long n;

	while(cin>>n){
		cout<<longitud(n)<<endl;
	}
	return 0;
}

