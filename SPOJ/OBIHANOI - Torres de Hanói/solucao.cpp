#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main(){
	int n;
	int teste = 1;
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}
		long int r = pow(2, n)-1; 
		cout << "Teste " << teste << endl << r << endl << endl;
		teste++;
	}

	return 0;
}
