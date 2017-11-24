#include <bits/stdc++.h>
#define MAXN 440

using namespace std;

int tempo;
int d[MAXN];
int low[MAXN];

struct Grafo
{
	bool visitados[MAXN];
	vector<int> vizinhos[MAXN];

	Grafo()
	{
		tempo = 0;
		memset(visitados, 0, sizeof visitados);
	}

	void addAresta(int u, int v)
	{
		vizinhos[u].push_back(v);
		vizinhos[v].push_back(u);
	}

	void DFS(int u, int pai, set<int> &r)
	{
		visitados[u] = true;
		d[u] = low[u] = tempo++;
		int num_filhos = 0;
		bool any = false;

		for(auto v : vizinhos[u])
		{
			if(v == pai)
				continue;

			if(!visitados[v])
			{
				DFS(v, u, r);

				num_filhos++;

				if(low[v] >= d[u])
					any = true;

				low[u] = min(low[u], low[v]);
			}
			else
			{
				low[u] = min(low[u], d[v]);
			}
		}

		if((!u && num_filhos >= 2) || (u && any))
			r.insert(u);
	}
	
	set<int> vertices_de_corte()
	{
		set<int> r;

		DFS(0, 0, r);

		return r;
	}
};

int main(int argc, char const *argv[])
{
	int N, M;

	int teste = 1;

	while(scanf("%d %d", &N, &M) && N + M)
	{
		Grafo g;

		for (int i = 0, u, v; i < M; ++i)
			scanf("%d %d", &u, &v), g.addAresta(u - 1, v - 1);

		set<int> r = g.vertices_de_corte();

		printf("Teste %d\n", teste++);

		if(r.empty())
			puts("nenhum");
		else
		{
			for(auto u : r)
				printf("%d ", u + 1);
			puts("");
		}

		puts("");
	}

	return 0;
}