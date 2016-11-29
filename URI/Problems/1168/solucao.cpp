#include <iostream>
#include <cstring>

using namespace std;

int valor(char n){
	int x = n - '0';
	switch(x){
		case 1:
			return 2;
			break;
		case 2:
			return 5;
			break;
		case 3:
			return 5;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 3;
			break;
		case 8:
			return 7;
			break;
		case 9:
			return 6;
			break;
		case 0:
			return 6;
			break;
	
	}
		
}

void imprime(string num){
	int leds = 0;
	int tam = num.length();
	for(int j=0;j < tam; j++){
		leds += valor(num[j]);
	}
	
	cout << leds << " leds" << endl;
}

int main(){

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string num;
		cin >> num;
		imprime(num);
	}


	return 0;
}
