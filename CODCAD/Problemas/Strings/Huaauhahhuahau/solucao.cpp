#include <iostream>

using namespace std;

bool vogal(char x){
	switch(x){
		case 'a':
			return true;
		case 'e':
			return true;
		case 'i':
			return true;
		case 'o':
			return true;
		case 'u':
			return true;
		default:
			return false;
	}
}

int main(int argc, char const *argv[])
{
	string risada;
	cin >> risada;
	int tam = risada.length(), y = 0;
	tam--;
	//Enquanto eu não verificar se uma metade é igual a outra...
	while(tam > y){
		//Se o caractere da posicao 'tam' for uma consoante, não faz nada...
		if(!vogal(risada[tam])){
			tam--;
			continue;
		//Se o caractere da posicao 'y' for uma consoante, não faz nada...
		}else if(!vogal(risada[y])){
			y++;
			continue;
		//Se chegou até aqui quer dizer que os dois são vogais...
		//Então se as vogais forem diferentes, a resposta é 'N'
		}else if(risada[tam] != risada[y]){
			cout << 'N' << endl;
			return 0;
		//Se forem iguais passa para o proximo caracter dos dois lados...
		}else{
			tam--;
			y++;
		}
	}
	//Se chegou até aqui é porque não entrou no 'N'...
	//Logo a resposta é 'S'...
	cout << 'S' << endl;
	return 0;
}