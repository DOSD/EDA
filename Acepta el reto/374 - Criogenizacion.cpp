#include <iostream>

using namespace std;

int main() {

	int n,contMenor, contMayor;
	long long m, menor, mayor; 
	cin>>n;

	for (int i =0; i < n; i++){
		contMenor = 0; contMayor = 0;
		cin>>m;
		menor = m;
		mayor = m;
		while(m != 0){
			if (m == mayor)
				contMayor++;
			if(m > mayor){
				mayor = m;
				contMayor = 1;
			}
			if(m == menor)
				contMenor++;
			if(m < menor){
				menor = m;
				contMenor = 1;
			}
			cin>>m;
		}
		cout << menor <<" "<< contMenor<< " "<< mayor<< " "<< contMayor << "\n";
	}
	return 0;
}