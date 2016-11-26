#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	char letra;
	cin >> letra;
	string palavra;
	int qtd_palavras = 0;
	int qtd_letras = 0;

	char x;
	scanf(" %c", &x);
	while(x != '\n'){
		if(x != ' '){
			palavra += x;
		}else{
			size_t achou = palavra.find(letra);
			if(achou != string::npos){
				qtd_letras++;
			}
			palavra = "";
			qtd_palavras++;
		}
		scanf("%c", &x);
	}
	qtd_palavras++;
	size_t achou = palavra.find(letra);
	if(achou != string::npos){
		qtd_letras++;
	}
	double r = qtd_letras * 100;
	r /= qtd_palavras;
	printf("%.1f\n", r);
	return 0;
}