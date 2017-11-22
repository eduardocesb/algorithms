#include <bits/stdc++.h>
#define MAXN 110

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

	void DFS(int u)
	{
		visitados[u] = true;
		for(auto v : vizinhos[u])
			if(!visitados[v])
				DFS(v);
	}
};

int main(int argc, char const *argv[])
{
	int T, N, M;

	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d %d", &N, &M);
		Grafo g;

		for (int i = 0, u, v; i < M; ++i)
			scanf("%d %d", &u, &v), g.addAresta(u, v);

		int r = 0;
		for (int i = 1; i <= N; ++i)
			if(!visitados[i])
				r++, g.DFS(i);

		r--;

		if(!r)
			printf("Caso #%d: a promessa foi cumprida\n", t);
		else
			printf("Caso #%d: ainda falta(m) %d estrada(s)\n", t, r);
	}

	return 0;
}