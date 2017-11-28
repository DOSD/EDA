#include <iostream>
#include <string>

using namespace std;

const int Max = 200000;

void resuelve(string &s){
	
	int i = s.length()-1,semaforo= -1;
	
	while (i >= 0){
		if(s[i] != '.' && s[i] != '|' && semaforo < 0)
			s[i]='.' ;
		
		if(i != semaforo-1 && semaforo >= 0 && s[i] != '.' && s[i] != '|'){
			s[semaforo-1] = s[i];
			s[i] = '.';
			semaforo--;
		}
		if(s[i] == '|')
			semaforo = i;
		if(s[i] != '.' && s[i] != '|' )
			semaforo = i;
		
		--i;
	}
}


int main () {
	int n,i; 
	int a;
	string s;
	
	//cout<<s.max_size();
	while(cin>>s){
		resuelve(s);
		cin>>n;
		i = 0;
		while(i<n-1){
			cin>>a;
			cout<<s[a-1]<<" ";
			i++;
		}
		cin>>a;
		cout<<s[a-1]<<endl;
	}
	return 0;
	
}
