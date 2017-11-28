#include <iostream>

using namespace std;

int main(){
	long int n,a,max;
	
	cin>>n;
	
	while(n >= 1 && std::cin){
		max=0;
		for(long int i=0;i < n;++i){
			cin>>a;
			if(a > max)
				max=a;
		}
		cout<<max<<endl;
		cin>>n;
	}
	return 0;
}
