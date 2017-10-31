#include <bits/stdc++.h>
#define MAXN 110
#define LADO_A false
#define LADO_B true

using namespace std;

int N, M;
int divisores[MAXN];
int multiplos[MAXN];

bool grafo[MAXN][MAXN];

void precalc(){
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			grafo[i][j] = (!multiplos[j]) || ((divisores[i]) && !(multiplos[j] % divisores[i]));
}

int visitados[MAXN][2], cont = 1;
int emparelhamento_A[MAXN];
int emparelhamento_B[MAXN];

bool DFS(int v, bool lado = LADO_A){
	visitados[v][lado] = cont;

	if(lado == LADO_B)
		if(emparelhamento_B[v] == -1)
			return true;
		else if(visitados[emparelhamento_B[v]][LADO_A] != cont)
			return DFS(emparelhamento_B[v], LADO_A);
		else;
	else
		for (int u = 0; u < M; ++u)
			if(grafo[v][u] && visitados[u][LADO_B] != cont && DFS(u, LADO_B)){
				emparelhamento_A[v] = u;
				emparelhamento_B[u] = v;
				
				return true;
			}

	return false;
}

int solve(){
	int r = 0, i;

	memset(emparelhamento_A, -1, sizeof(emparelhamento_A));
	memset(emparelhamento_B, -1, sizeof(emparelhamento_B));

	//Enquanto eu conseguir montar um caminho aumentante, eu posso aumentar a minha resposta...
	for(bool ok = true; ok; r++, cont++)
		//Tento montar um caminho aumentante começando no vertice 'i' do lado 'A'...
		//Até conseguir...
		for (i = 0, ok = false; !ok && i < N; ++i)
			//Caso eu não tenha o visitado e ele não esteja emparelhado...
			if(visitados[i][LADO_A] != cont && emparelhamento_A[i] == -1)
				ok = DFS(i);
	return r;
}

int main(int argc, char const *argv[])
{
	int T;

	scanf("%d", &T);

	//Para cada caso de teste...
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d", &N);
		//Leio os valores de 'A', ou seja, os divisores...
		for (int i = 0; i < N; ++i)
			scanf("%d", &divisores[i]);

		scanf("%d", &M);
		//Leio os valores de 'B', ou seja, os múltiplos...
		for (int i = 0; i < M; ++i)
			scanf("%d", &multiplos[i]);

		//Monto o Grafo baseado na divisibilidade...
		precalc();

		//Calculo a resposta e imprimo o resultado...
		printf("Case %d: %d\n", t, solve() - 1);
	}

	return 0;
}