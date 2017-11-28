#include <iostream>

using namespace std;

int main(){
	int n,m;
	
	cin>>n;
	
	while(n!=0){
		int suma = 0;
		int suma2 = 0;
		
		for(int i = 0; i<n-1;++i){
			cin>>m;
			suma += m;
			suma2 += i+1;
		}
		
		suma2 +=n;
		
		cout<<suma2-suma<<endl;
		
		cin>>n;
	}
	
	return 0;
}
