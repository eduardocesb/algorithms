#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 110
#define pii pai<int, int>

using namespace std;

double distancia[MAXN][MAXN];

struct Grafo
{
	int V;
	vector<int> vizinhos [MAXN];

	Grafo(int V) : V(V)
	{
		memset(distancia, 0, sizeof(distancia));
	}

	void addAresta(int u, int v, int c)
	{
		distancia[u][v] = distancia[v][u] = c;
	}

	double Floyd_Warshall()
	{
		for (int k = 0; k < V; ++k)
			for (int i = 0; i < V; ++i)
				for (int j = 0; j < V; ++j)
					distancia[i][j] = max(distancia[i][j], distancia[i][k] * distancia[k][j] / 100.0);

		return distancia[0][V - 1];
	}
};

int main(int argc, char const *argv[])
{
	//optimize;

	int N, M, A, B, C;

	while(scanf("%d %d", &N, &M) == 2)
	{
		Grafo g(N);

		for (int i = 0; i < M; ++i)
			scanf("%d %d %d", &A, &B, &C), g.addAresta(A - 1, B - 1, C);

		printf("%.6lf percent\n", g.Floyd_Warshall());
	}

	return 0;
}