#include <iostream>
#include <cstdio>

using namespace std;

char letras[] = {' ', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


int valor(char x){
	for(int cont=1;cont<53;cont++){
		if(x == letras[cont]){
			return cont;
		}
	}
	return 0;
}

bool primo(int x){
	for(int cont=2; cont <x; cont++){
		if(x%cont == 0){
			return false;
		}
	}
	return true;
}

int main(){
	char c;
	int r=0;
	while(scanf("%c", &c) !=EOF){
		r += valor(c);
		scanf("%c", &c);
		while(c != '\n' ){
			r+= valor(c);	
			scanf("%c", &c);
		}
		if(primo(r) == true){
			cout << "It is a prime word." << endl;
		}else{
			cout << "It is not a prime word." << endl;
		}
		r = 0;
	}
	return 0;
}
