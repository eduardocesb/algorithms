#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int N, M;

struct Grafo
{
	vector<int> vizinhos[2 * MAXN];
	bool visitados[2 * MAXN];
	int filhos[2 * MAXN];

	Grafo(){
		memset(visitados, 0, sizeof(visitados));
	}

	void add(int v1, int v2){
		vizinhos[v1].push_back(v2);
	}

	int DFS(int u){

		if(visitados[u]) return filhos[u];

		visitados[u] = true;

		int r = 0;

		for(auto v : vizinhos[u])
			r = max(r, DFS(v));

		return filhos[u] = 1 + r;
	}
};

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);

	Grafo g;

	for (int i = 0, u, v, d; i < M; ++i){
		scanf("%d %d %d", &u, &d, &v);

		if(d < 0) swap(u, v);

		g.add(u, v);
	}


	int melhor_par = 0;
	int melhor_impar = 0;

	//Calcula o maior nivel comecando por um nó impar...
	for (int i = 1; i <= 2 * N; i += 2)
		melhor_impar = max(melhor_impar, g.DFS(i));

	//Calcula o maior nivel comecando por um nó par...
	for (int i = 2; i <= 2 * N; i += 2)
		melhor_par = max(melhor_par, g.DFS(i));


	//Se tiverem o mesmo nivel, a reposta é 1 a mais, pois tenho que escolher entre quem vai ser o primeiro...
	if(melhor_par == melhor_impar)
		printf("%d\n", melhor_par + 1);
	//Se não, é o maior deles...
	else
		printf("%d\n", max(melhor_par, melhor_impar));

	return 0;
}