#include <stdio.h>
#define MAXT 1000100 

int tam; 
char pilha[MAXT];

void pop(){
	if(tam>0) tam--; 
 } 

void push(char x){
	pilha[++tam]=x; 
} 
void clear(){
	tam=0;
}

int top(){
	return pilha[tam]; 
}

char y =' ';
int i, n;
char res = ' ';

int main(){
	
	return 0;
}
