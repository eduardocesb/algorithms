#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 550
#define INFINITO 10000000

using namespace std;

int distancia[MAXN][MAXN];

struct Grafo
{
	int V;
	vector<int> vizinhos[MAXN];

	Grafo(int V) : V(V)
	{	
		for (int i = 1; i <= V; ++i)
			for (int j = 1; j <= V; ++j)
				distancia[i][j] = INFINITO;
	}

	void addAresta(int u, int v, int c)
	{
		vizinhos[u].push_back(v);

		if(distancia[v][u] != INFINITO)
			distancia[u][v] = distancia[v][u] = 0;
		else
			distancia[u][v] = c;
	}

	void Floyd_Warshall()
	{
		for (int k = 1; k <= V; ++k)
			for (int i = 1; i <= V; ++i)
				for (int j = 1; j <= V; ++j)
					distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);
	}
};

int main(int argc, char const *argv[])
{
	//optimize;
	int N, E, K;

	while(scanf("%d %d", &N, &E) && N + E)
	{
		Grafo g(N);

		for (int i = 0, u, v, c; i < E; ++i)
		{
			scanf("%d %d %d", &u, &v, &c);
			g.addAresta(u, v, c);
		}

		g.Floyd_Warshall();

		scanf("%d", &K);

		for (int i = 0, u, v; i < K; ++i)
		{
			scanf("%d %d", &u, &v);
			if(distancia[u][v] != INFINITO)
				printf("%d\n", distancia[u][v]);
			else
				puts("Nao e possivel entregar a carta");
		}

		cout << endl;
	}

	return 0;
}