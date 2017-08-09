#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int arvore[MAXN];
int lazy[MAXN];

void atualiza(int no, int i, int j, int a, int b, int valor){ 
	
	int esquerda = 2*no;     // índice do filho da esquerda
	int direita  = 2*no + 1; // índice do filho da direita
	int meio = (i + j)/2;
	
	if(lazy[no]){ // se existirem operações atrasadas a serem feitas, temos que fazê-las agora
		
		arvore[no] = lazy[no]*(j - i + 1); // já que somamos lazy[no] a cada valor de i a j, fazemos isso (j-i+1) vezes
		
		if(i != j){ // se i != j, o nó possui descendentes e temos que atualizar o valor de lazy deles
			lazy[direita]  = lazy[no];
			lazy[esquerda] = lazy[no];
		}
		
		lazy[no] = 0; // agora que realizamos as operações devidas, zeramos novamente o valor de lazy[no]
	}
	
	if(i > j || i > b || a > j) return; // se a atualização que vamos fazer não afeta esse nó, encerramos a função
	
	if(a <= i && j <= b){ // se a operação cobre o nó inteiro
		
		arvore[no] = valor*(j-i+1); // atualizamos o valor do nó
		
		// se o nó possui descendentes, atualizamos o valor de lazy de cada um deles
		// em vez de chamar a função recursiva. Isso é o que otimiza nosso tempo de execução
		if(i != j){
			lazy[direita] = valor;
			lazy[esquerda] = valor;
		}
	}
	
	else{ // caso a operação atualize apenas alguns valores do nó, chamamos a função nos dois filhos
		
		atualiza(esquerda,      i, meio, a, b, valor); // atualizamos o filho da esquerda
		atualiza( direita, meio+1,    j, a, b, valor); // atualizamos o filho da direita
		
		arvore[no] = arvore[esquerda] + arvore[direita]; // atualizamos o nó que estamos
	}
	
}

// queremos saber a soma de todos os valores de índice no intervalo [A, B]
int consulta(int no, int i, int j, int a, int b){
	
	int esquerda = 2*no;     // índice do filho da esquerda
	int direita  = 2*no + 1; // índice do filho da direita
	int meio = (i + j)/2;
	
	if(lazy[no]){ // se existirem operações atrasadas a serem feitas, temos que fazê-las agora
		
		arvore[no] = lazy[no]*(j - i + 1); // já que somamos lazy[no] a cada valor de i a j, fazemos isso (j-i+1) vezes
		
		if(i != j){ // se i != j, o nó possui descendentes e temos que atualizar o valor de lazy deles
			lazy[direita]  = lazy[no];
			lazy[esquerda] = lazy[no];
		}
		
		lazy[no] = 0; // agora que realizamos as operações devidas, zeramos novamente o valor de lazy[no]
	}
	
	if(i > j || i > b || a > j) return 0; // [i, j] e [a, b] são disjuntos, retornamos 0
	
	if(a <= i && j <= b) // se [i, j] está contido em [a, b], retornamos o valor do nó inteiro
		return arvore[no];
		
	else{ // retornamos então a soma da função chamada nos dois descendentes
		
		int soma_esquerda = consulta(esquerda,      i, meio, a, b);
		int soma_direita  = consulta( direita, meio+1,    j, a, b);
		
		return soma_esquerda + soma_direita;
	}
}

int main(int argc, char const *argv[])
{
	memset(arvore, 0, sizeof(arvore));
	memset(lazy, 0, sizeof(lazy));
	int N, Q, A, O, B, K, x;
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i){
		cin >> x;
		atualiza(1, 1, N, i, i, x);
	}

	for (int i = 0; i < Q; ++i)
	{
		cin >> O >> A >> B;
		if(O == 2)
			cout << consulta(1, 1, N, A, B) << endl;
		else{
			cin >> K;
			atualiza(1, 1, N, A, B, K);
		}
	}
	return 0;
}