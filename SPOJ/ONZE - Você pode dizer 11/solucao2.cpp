#include <iostream>
#include <string.h>	 

using namespace std;

int main(){
	char n[1001];
	bool achou;

	while (true){
		long int si = 0, sp = 0;
		cin.getline(n, 1001);
		int tam = strlen(n);
		achou = true;
		for (int i = 0; i < tam; i++){
			if (n[i] != '0'){ 
				achou = false;
				break;
			}

		}
		if (achou == true) break;

	  for (int i = tam - 1; i >= 0; i = i - 2) {
	  	si += n[i] - '0';
	  }
		for (int i = tam - 2; i >= 0; i = i - 2){
	  	sp += n[i] - '0';
	  }
	  if ((si - sp) % 11 == 0){
	  	cout << n << " is a multiple of 11." << endl;
	  }else{
	  	cout << n << " is not a multiple of 11." << endl;
	  }

	 }

	 return 0;

}
