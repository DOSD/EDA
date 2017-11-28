#include <iostream>
#include <string>

using namespace std;

void sol(int c, int v, string aux,string &res){
	if(c==0 && v==0)
		res += aux +" ";
		//cout<<aux<<" ";

	if(c > 0){
		sol(c-1,v,aux+"C",res);
	}
	if(v > 0){
		sol(c,v-1,aux+"V",res);
	}
}

int main(){
	int n,c,v,i=0;
	cin>>n;
	while(i<n){
		string s ="",res="";
		cin>>c>>v;
		sol(c,v,s,res);
		cout<<res.substr(0,res.size()-1);
		cout<<endl;
		++i;
	}

	return 0;
}