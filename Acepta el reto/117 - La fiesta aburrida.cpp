#include <iostream>

using namespace std;

int main(){
	
	int num,i;
	cin>>num;
	
	for(i=0; i<num;i++){
		
		string palabra,nombre;
		
		cin>>palabra>>nombre;
		
		cout<<"Hola, "<<nombre<<".\n";
	}
	return 0;
}
