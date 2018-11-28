#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define INFINITO 1000000000000000
#define MAXN 20100

using namespace std;

struct Aresta
{
	int U;
	ll L, C;

	Aresta(int u = 0, ll l = 0LL, ll c = 0LL)
	{
		U = u;
		L = l;
		C = c;
	}

	bool operator < (const Aresta &a) const
	{
		return L != a.L ? L > a.L : C > a.C;
	}
};

vector<Aresta> arestas[MAXN];
int N, M;

void addAresta(int a, int b, ll l, ll c)
{
	arestas[a].push_back(Aresta(b, l, c));
	arestas[b].push_back(Aresta(a, l, c));
}

ll Dijkstra()
{
	ll dist[MAXN], custo[MAXN];

	for(int i = 0; i < MAXN; i++) dist[i] = custo[i] = INFINITO;

	priority_queue<Aresta> pq;

	pq.push(Aresta(1, 0LL, 0LL));
	dist[1] = custo[1] = 0LL;

	while(!pq.empty())
	{
		int v, l, c, u = pq.top().U;
		pq.pop();

		for(auto no : arestas[u])
		{
			v = no.U;
			l = no.L;
			c = no.C;

			if((dist[v] > dist[u] + l) || ((dist[v] == dist[u] + l) && (custo[v] > c)))
			{
				dist[v] = dist[u] + l;
				custo[v] = c;
				pq.push(Aresta(v, dist[v], custo[v]));
			}
		}
	}
	
	ll r = 0LL;
	for(int i = 1; i <= N; i++)
		r += custo[i];
	return r;
}

int main(int argc, char** argv)
{
	optimize;

	cin >> N >> M;

	int a, b, l, c;

	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> l >> c;
		addAresta(a, b, l, c);
	}

	cout << Dijkstra() << endl;

	return 0;
}
