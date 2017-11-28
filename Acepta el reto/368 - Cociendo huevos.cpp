#include <iostream>	

using namespace std;

int resultado(int h, int c) {
	
	int result = 10;
	int division;
	
	division = h / c;
	if(h%c !=0)
		division++;
	result = result * division;
	
	return result;
}


int main() {
	int h, c;
	
	cin >> h >> c;
	
	while (h != 0 && c != 0) {
		
		cout << resultado(h,c)<<"\n";
		
		cin >> h >> c;
	}
	
	return 0;
}
