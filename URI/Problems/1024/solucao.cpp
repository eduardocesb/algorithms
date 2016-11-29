#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
char frase[1001];

void soma(int tam){	

	for(int i=0;i<tam;i++){
		if(isalpha(frase[i])){
			frase[i] += 3;
		}
	}
	
}

void inverte(int tam){

	char aux[tam];
	for(int i=0; i< tam; i++){
		aux[i] = frase[i];
	}
	int x=0;
	for(int i=tam-1; i>=0; i--){
		frase[i] = aux[x];
		x++;
	}
}

void desloca(int tam){
	
	int meio = tam/2;
	for(int i=meio; i<tam;i++){
		frase[i] -= 1;
	}

}

int main(){

	int n;
	scanf("%d", &n);
	char aux;
	scanf("%c", &aux);
	for(int y=0;y<n;y++){
		cin.getline(frase, 1001);
		int tam = strlen(frase);
	
		soma(tam);
		//cout << frase << endl;
	
		inverte(tam);
		//cout << frase << endl;
	
		desloca(tam);
		cout << frase << endl;
	}
	return 0;

}
