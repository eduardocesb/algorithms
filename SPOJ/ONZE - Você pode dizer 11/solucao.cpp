#include <iostream>
#include <stdio.h>

using namespace std;

bool achou;

bool resultado (int Si, int Sp){
	if(Si - Sp == 0){
		achou = true;
	}
	if(Si-Sp >0 && (Si-Sp)%11 == 0 ){
		achou = true;
	}
	
	if(Si-Sp < 0){
		resultado(Si+11, Sp);
	}
	
	return achou;
}

int main(){
	
	char c;
	scanf("%c", &c);
	while(c != '0'){
		achou = false;
		int par = 0;
		int impar = 0;
		char num[1001];
		for(int i=0;i<1001;i++){
			num[i] = '\0';
		}
		num[0] = c;
		par += int(c) - 48;
		int qtd=1;
		scanf("%c", &c);
		while(c != '\n'){
			num[qtd] = c;
			if(qtd%2 == 0){
				par += int(c) - 48;
			}else{
				impar += int(c) - 48;
			}
			qtd++;
			scanf("%c", &c);
		}
		if(qtd%2 == 1){
			if(resultado(impar, par) == true){
				cout << num << " is a multiple of 11." << endl;
			}else{
				cout << num << " is not a multiple of 11." << endl;
			}
		}else{
			if( resultado(par, impar) == true){
				cout << num << " is a multiple of 11." << endl;
			}else{
				cout << num << " is not a multiple of 11." << endl;
			}
		}
		
		scanf("%c", &c);
	}
	return 0;
}
