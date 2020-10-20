#include <bits/stdc++.h>
#define MAXN 1010
#define MAXL 20

using namespace std;

int ancestral[MAXN][MAXL];
int nivel[MAXN];

struct Grafo
{
	vector<int> vizinhos[MAXN];
	int V;

	Grafo(int V): V(V)
	{
		memset(nivel, -1, sizeof(nivel));
		memset(ancestral, -1, sizeof(ancestral));
	}

	void addAresta(int u, int v)
	{
		vizinhos[u].push_back(v);
		vizinhos[v].push_back(u);
	}

	void DFS(int u = 0, int l = 0)
	{
		nivel[u] = l;
		for(auto v : vizinhos[u])
			if(nivel[v] == -1)
			{
				ancestral[v][0] = u;

				DFS(v, l + 1);
			}
	}

	void precalc()
	{
		DFS();

		for(int i = 1; i < MAXL; i++)
			for(int u = 0; u < V; u++)
				if(ancestral[u][i - 1] != -1)
					ancestral[u][i] = ancestral[ancestral[u][i - 1]][i - 1];
	}

	int LCA(int u, int v)
	{
		if(nivel[u] < nivel[v])
			swap(u, v);

		for (int i = MAXL - 1; i >= 0 ; --i)
			if(ancestral[u][i] != -1 && nivel[ancestral[u][i]] >= nivel[v])
				u = ancestral[u][i];

		if(u == v)
			return u;

		for (int i = MAXL - 1; i >= 0 ; --i)
			if(ancestral[u][i] != -1 && ancestral[v][i] != -1 && ancestral[u][i] != ancestral[v][i])
			{
				u = ancestral[u][i];
				v = ancestral[v][i];
			}

		return ancestral[u][0];
	}
};

int main(int argc, char const *argv[])
{
	int T, N, M, Q;
	scanf("%d", &T);

	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);

		Grafo g(N);

		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &M);
			for (int j = 0, v; j < M; ++j)
			{
				scanf("%d", &v);
				g.addAresta(i, v - 1);
			}
		}

		g.precalc();

		scanf("%d", &Q);

		printf("Case %d:\n", t);

		for (int i = 0, u, v; i < Q; ++i)
		{
			scanf("%d %d", &u, &v);

			printf("%d\n", g.LCA(u - 1, v - 1) + 1);
		}
	}

	return 0;
}