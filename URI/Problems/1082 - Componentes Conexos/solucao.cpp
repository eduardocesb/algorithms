#include <bits/stdc++.h>
#define MAXN 30

using namespace std;

bool visitados[MAXN];

struct Grafo
{
	vector<int> vizinhos[MAXN];

	Grafo()
	{
		memset(visitados, 0, sizeof(visitados));
	}

	void addAresta(int u, int v)
	{
		vizinhos[u].push_back(v);
		vizinhos[v].push_back(u);
	}

	void DFS(int v, set<int> &componentes)
	{
		visitados[v] = true;
		componentes.insert(v);

		for(auto u : vizinhos[v])
			if(!visitados[u])
			{
				DFS(u, componentes);
			}
	}
};

int main(int argc, char const *argv[])
{
	int N, V, E;
	char u, v;

	scanf("%d", &N);
	for (int t = 0; t < N; ++t)
	{
		scanf("%d %d", &V, &E);

		Grafo g;

		for (int i = 0; i < E; ++i)
		{
			scanf(" %c %c", &u, &v);
			g.addAresta(u - 'a', v - 'a');
		}

		int r = 0;

		printf("Case #%d:\n", t + 1);

		for (int i = 0; i < V; ++i)
		{
			set<int> componentes;

			if(!visitados[i])
			{
				r++;
				g.DFS(i, componentes);

				for(auto u : componentes)
					printf("%c,", 'a' + u);
				puts("");
			}

		}

		printf("%d connected components\n\n", r);
	}

	return 0;
}