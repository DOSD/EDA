#include <iostream>

using namespace std;

const int N = 100000;

void resuelve(int a[], int n){
	int sum = a[n-1];
	int pos = -1;
	
	for(int i  = n-2; i >= 0;--i){
		if(a[i] == sum){
			pos = i+1;
			if(pos != -1 && a[i] >= sum)
				pos = i+1;
		}
		sum += a[i];
	}
	
	if(pos != -1)
		cout<<"SI "<<pos<<endl;
	else cout<<"NO"<<endl;
	
	
}

int main(){
	int n;
	
	cin>>n;
	
	int a[N];
	
	while(n != 0){
		
		for(int i = 0; i < n; ++i)
			cin>>a[i];
		resuelve(a,n);
		cin>>n;
	}
	
	
	return 0;
}
