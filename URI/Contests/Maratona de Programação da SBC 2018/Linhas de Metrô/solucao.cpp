#include <bits/stdc++.h>
#define MAXN 500010
#define MAXL 25

using namespace std;

int ancestral[MAXN][MAXL];
int nivel[MAXN];
bool visitados[MAXN];
int N, M;
vector<int> vizinhos[MAXN];

void dfs(int u)
{
	int tam = vizinhos[u].size(), v;
	for(int i = 0; i < tam; i++)
	{
		v = vizinhos[u][i];
		if(visitados[v]) continue;
		visitados[v] = true;

		nivel[v] = nivel[u] + 1;
		ancestral[v][0] = u;
		dfs(v);
	}
}

void precalc()
{
	visitados[1] = true;
	nivel[1] = 0;
	dfs(1);

	for(int u = 1; u < MAXL; u++)
		for(int i = 1; i <= N; i++)
			if(ancestral[i][u - 1] != -1)
				ancestral[i][u] = ancestral[ancestral[i][u - 1]][u - 1];
}

int LCA(int u, int v)
{
	if(nivel[u] < nivel[v]) swap(u, v);

	for(int j = MAXL - 1; j >= 0; j--)
		if(ancestral[u][j] != -1 && nivel[ancestral[u][j]] >= nivel[v])
			u = ancestral[u][j];

	if(u == v) return v;

	for(int j = MAXL - 1; j >= 0; j--)
		if(ancestral[u][j] != -1 && ancestral[v][j] != -1 && ancestral[u][j] != ancestral[v][j])
		{
			u = ancestral[u][j];
			v = ancestral[v][j];
		}

	return ancestral[v][0];
}

int main()
{
	memset(ancestral, -1, sizeof ancestral);
	memset(visitados, 0, sizeof visitados);
	int u, v, x, y;
	scanf("%d %d", &N, &M);

	for(int i = 1; i < N; i++)
	{
		scanf("%d %d", &u, &v);
		vizinhos[u].push_back(v);
		vizinhos[v].push_back(u);
	}

	precalc();

	while(M--)
	{
		scanf("%d %d %d %d", &u, &v, &x, &y);

		int lcauv = LCA(u, v);
		int lcaxy = LCA(x, y);

		if(nivel[lcauv] < nivel[lcaxy])
		{
			swap(u, x);
			swap(v, y);
			swap(lcauv, lcaxy);
		}

		int r = 0;
		bool ok = false;

		int lcalcauvx = LCA(lcauv, x);
		int lcalcauvy = LCA(lcauv, y);

		if(lcalcauvx == lcauv)
		{
			int lcaux = LCA(u, x);
			int lcavx = LCA(v, x);
			ok = true;
			r += max(0, nivel[lcaux] - nivel[lcauv]);
			r += max(0, nivel[lcavx] - nivel[lcauv]);
		}
		if(lcalcauvy == lcauv)
		{
			ok = true;
			int lcauy = LCA(u, y);
			int lcavy = LCA(v, y);
			r += max(0, nivel[lcauy] - nivel[lcauv]);
			r += max(0, nivel[lcavy] - nivel[lcauv]);
		}

		printf("%d\n", (r + ok));
	}

	return 0;
}
