#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAXN 10010

using namespace std;

int tempo;

struct Grafo
{
	int d[MAXN];
	int low[MAXN];
	bool visitados[MAXN];
	int pai[MAXN];

	vector<int> vizinhos[MAXN];

	Grafo(int V)
	{
		for (int i = 0; i < V; ++i)
			pai[i] = i;

		tempo = 0;
		memset(visitados, 0, sizeof(visitados));
	}

	void addAresta(int u, int v)
	{
		vizinhos[u].push_back(v);
		vizinhos[v].push_back(u);
	}

	int find(int x)
	{
		return (pai[x] == x ? x : pai[x] =  find(pai[x]));
	}

	void join(int u, int v)
	{
		pai[find(u)] = find(v);
	}

	char query(int u, int v)
	{
		return (find(u) == find(v) ? 'Y' : 'N');
	}

	void DFS(int u = 0, int pai = 0)
	{
		visitados[u] = true;
		d[u] = low[u] = tempo++;

		for(int v : vizinhos[u])
			if(!visitados[v])
			{
				DFS(v, u);

				low[u] = min(low[u], low[v]);

				//a aresta u <--> v é uma ponte...
				if(low[v] > d[u])
					join(u, v);
			}
			else if(v != pai)
			{
				low[u] = min(low[u], d[v]);
			}
	}
};

int main(int argc, char const *argv[])
{
	int N, M, Q;

	while(scanf("%d %d %d", &N, &M, &Q) && N + M + Q)
	{
		Grafo g(N);

		for (int i = 0, u, v; i < M; ++i)
			scanf("%d %d", &u, &v), g.addAresta(u - 1, v - 1);

		g.DFS();

		for (int i = 0, u, v; i < Q; ++i)
		{
			scanf("%d %d", &u, &v);

			printf("%c\n", g.query(u - 1, v - 1));
		}

		puts("-");
	}

	return 0;
}