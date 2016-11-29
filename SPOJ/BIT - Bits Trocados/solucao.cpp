#include <iostream>

using namespace std;

int main(){
	
	int num_teste = 1;
	int n;
	cin >> n;
	while(n != 0){
		int I, J, K, L;
		I = n/50;
		n = n%50;
		J = n/10;
		n = n%10;
		K = n/5;
		n = n%5;
		L = n/1;
		
		cout << "Teste " << num_teste << endl;
		cout << I << " " << J << " " << K << " " << L << endl << endl;
		num_teste++;
		cin >> n;
	}

	return 0;
}
