#include <iostream>

using namespace std;

long long sol(long long m){
	if(m < 6)
		return m;
	return sol(m/6)*10 + m%6;
	
	
}

int main(){
	long long n, i = 0, m;
	cin>>n;
	
	while(i < n){
		cin>>m;
		cout<<sol(m)<<endl;
		++i;
	}
	
	
	return 0;
}
