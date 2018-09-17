#include <bits/stdc++.h>
#define INFINITO 1000000000
#define MAXN 110
#define MP make_pair
#define PB push_back
#define pii pair<int, int>

using namespace std;

int Z, S, K, U, V, T, B;
int zonas[MAXN];
int linha[MAXN];
int dist[MAXN];

vector<pii> grafo[MAXN];

int Dijkstra()
{
	for(int i = 0; i < MAXN; i++) dist[i] = INFINITO;

	priority_queue<pii, vector<pii>, greater<pii> > pq;

	dist[U] = 2;

	pq.push(MP(dist[U], U));

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

for(auto v : grafo[u])
		{
			if(dist[v.first] > dist[u] + v.second)
			{
				dist[v.first] = dist[u] + v.second;
				pq.push(MP(dist[v.first], v.first));
			}
		}
	}

	return dist[V];
}

int main(int argc, char** argv)
{
	int x;

	while(scanf("%d %d", &Z, &S) && (Z || S))
	{
		for(int i = 0; i < MAXN; i++) grafo[i].clear();

		for(int i = 1; i <= Z; i++)
		{
			scanf("%d", &K);
			for(int j = 0; j < K; j++)
			{
				scanf("%d", &x);
				zonas[x] = i;
			}
		}

		scanf("%d %d", &T, &B);

		//Trem...
		while(T--)
		{
			scanf("%d", &K);
			for(int i = 0; i < K; i++)
				scanf("%d", &linha[i]);

			for(int i = 0; i < K; i++)
			{
				int custo = 0;
				for(int j = i + 1; j < K; j++)
				{
					if(zonas[linha[j]] != zonas[linha[i]])
						custo += 4;
					grafo[linha[i]].PB(MP(linha[j], custo));
					grafo[linha[j]].PB(MP(linha[i], custo));
				}
			}
		}

		//Ônibus
		while(B--)
		{
			scanf("%d", &K);
			for(int i = 0; i < K; i++)
				scanf("%d", &linha[i]);

			for(int i = 0; i < K; i++)
				for(int j = i + 1; j < K; j++)
				{
					grafo[linha[i]].PB(MP(linha[j], 1));
					grafo[linha[j]].PB(MP(linha[i], 1));
				}
		}

		scanf("%d %d", &U, &V);

		printf("%d\n", Dijkstra());
	}


	return 0;
}
