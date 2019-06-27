#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define INFINITO 1000000010
#define pii pair<int, int>
#define MAXN 1010

using namespace std;

vector<int> grafo[MAXN], monstro[MAXN];
int dp[MAXN][MAXN], mana[MAXN], pontos[MAXN], custo[MAXN], distancia[MAXN], M, N, G, K;

int f(int m, int p)
{
	if(p <= 0) return 0;
	if(m >= M) return INFINITO;
	if(dp[m][p] != -1) return dp[m][p];

	return dp[m][p] = min(f(m + 1, p), mana[m] + f(m, p - pontos[m]));
}

void addAresta(int u, int v)
{
	grafo[u].push_back(v);
	grafo[v].push_back(u);
}

void precalc()
{
	for(int i = 0; i < MAXN; i++)
	{
		int tam = monstro[i].size();
		for(int j = 0; j < tam; j++)
			custo[i] += f(0, monstro[i][j]);
	}
}

int dijkstra(int origem, int destino)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(custo[origem], origem));
	distancia[origem] = custo[origem];

	while(!pq.empty())
	{
		int u = pq.top().second;

		pq.pop();

		int tam = grafo[u].size();

		for(int i = 0; i < tam; i++)
		{
			int v = grafo[u][i];
			int c = custo[v];

			if(distancia[v] > c + distancia[u])
			{
				distancia[v] = c + distancia[u];
				pq.push(make_pair(distancia[v], v));
			}
		}
	}

	return distancia[destino];
}

int main(int argc, char const *argv[])
{
	optimize;

	int u, v;

	while((cin >> M >> N >> G >> K) && (M || N || G || K))
	{
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < MAXN; i++)
		{
			grafo[i].clear();
			distancia[i] = INFINITO;
			custo[i] = 0;
			monstro[i].clear();
		}

		for(int i = 0; i < M; i++)
			cin >> mana[i] >> pontos[i];

		for(int i = 0; i < G; i++)
		{
			cin >> u >> v;
			addAresta(u, v);
		}

		for(int i = 0; i < K; i++)
		{
			cin >> u >> v;
			monstro[u].push_back(v);
		}

		precalc();

		int r = dijkstra(1, N);

		cout << (r == INFINITO ? -1 : r) << endl;
	}

	return 0;
}