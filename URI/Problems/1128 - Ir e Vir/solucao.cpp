#include <bits/stdc++.h>
#define MAXN 2020

using namespace std;


struct Grafo
{
	vector<int> vizinhos[MAXN];
	bool visitados[MAXN];

	Grafo()
	{
		memset(visitados, 0, sizeof(visitados));
	}

	void addAresta(int u, int v)
	{
		vizinhos[u].push_back(v);
	}

	int DFS(int u)
	{
		visitados[u] = true;

		int r = 1;
		for(auto v : vizinhos[u])
			if(!visitados[v])
				r += DFS(v);

		return r;
	}
};

int main(int argc, char const *argv[])
{
	int N, M, U, V, P;

	while(scanf("%d %d", &N, &M) && N + M)
	{
		Grafo a, b;

		for (int i = 0; i < M; ++i)
		{
			scanf("%d %d %d", &U, &V, &P);

			a.addAresta(U, V);
			b.addAresta(V, U);
			if(--P)
				a.addAresta(V, U), b.addAresta(U, V);
		}

		printf("%d\n", (a.DFS(1) == N && b.DFS(1) == N ? 1 : 0));
	}

	return 0;
}