#include <iostream>

using namespace std;

const int Max = 200000;

int func(int a[],int n,int m){
	int ret=1;
	int i=0, j=1,aux;
	while (j < n){
		while(a[j] -a[i] >= m)
			++i;
		if(ret < j - i +1)
			ret = j - i +1;
		++j;
	}
	
	
	
	return ret;
}

int main () {
	int n,m,i; 
	int a[Max];
	
	cin>>n;
	cin>>m;
	
	while(n != 0 && m != 0){
		i=0;
		while(i < n){
			cin >> a[i];
			i++;
			
		}
		cout<<func(a,n,m)<<endl;
		cin>>n;
		cin>>m;
	}
	return 0;
}
