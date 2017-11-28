#include <iostream>

using namespace std;

long long sol(long long n, long long m){
	if(m < 10 || n < 10)
		return 0;
	if(n == m)
		return 1;
	
	if(n<m){
		if(m%n == 0)
			return m/n;
		else 
			return sol(n,m-(n*(m/n))) + m/n ;
	}
	else {
		if(n%m == 0)
			return n/m;
		else
			return sol(n-(m*(n/m)),m) + n/m ;
	}
	
}

int main(){
	long long n, m;
	cin>>n>>m;
	
	while(n > 0 && m > 0){
		cout<<sol(n,m)<<endl;
		cin>>n>>m;
	}
	return 0;
}
