#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	char x;
	cin >> N;
	stack<char> pilha;
	int qtd = 0;
	//Leio o '\n' que vem depois do número...
	scanf("%c", &x);
	while(qtd != N){
		//Leio cada caracter...
		scanf("%c", &x);
		if(x == '\n')
			qtd++;
		if(x == '{')
			pilha.push(x);
		else if(x == '}'){
			if(pilha.empty()){
				cout << 'N' << endl;
				return 0;
			}
			pilha.pop();
		}
	}

	if(pilha.empty())
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	return 0;
}