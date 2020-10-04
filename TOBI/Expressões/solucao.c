#include <stdio.h>
#include <string.h>

#define MAXT 1000100

char a[MAXT];
char pilha[MAXT];
int tam; 
void pop(){ 
	if(tam>0){
		tam--;  
	}
} 

void push(char x){ 
	pilha[++tam]=x; 
} 
void clear(){ 
	tam=0; 
} 
char top(){ 
	return pilha[tam]; 
} 

int abre(char c){
	if((c == '{') || (c == '(') || (c == '[')){
		return 1;
	}else{
		return 0;
	}
}

int fecha(char c){
	switch (c){
      case ')':
      	return '(';
      case ']':
        return '[';
      case '}':
        return '{';
    }
}


int main(int argc, char const *argv[]){
	int n = 0;
	scanf("%d" , &n);
	char x;
	int i,j;
	int qtd;
	int deu_errado = 0;
	for(i = 0; i<n; i++){
		deu_errado = 0;
		tam = 0;
		clear();
		scanf("%s", a);
		qtd = strlen(a);
		for(j=0;j<qtd;j++){
			if(abre(a[j]) == 1){
				push(a[j]);
			}else{
				if(fecha(a[j]) == top()){
					pop();
				}else{
					deu_errado = 1;
					break;
				}
			}
		}
		if(deu_errado == 1 || tam != 0){
			printf("N\n");
		}else{
			printf("S\n");	
		}
	}
	return 0;
}