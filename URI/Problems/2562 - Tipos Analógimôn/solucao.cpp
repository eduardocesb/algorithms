#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 1010

using namespace std;

struct Grafo
{
	int pai[MAXN];
	int peso[MAXN];

	Grafo(int V)
	{
		for(int i = 1; i <= V; i++)
		{
			pai[i] = i;
			peso[i] = 1;
		}
	}

	int find(int x)
	{
		return (pai[x] == x ? x : pai[x] = find(pai[x]));
	}

	void join(int u, int v)
	{
		u = find(u);
		v = find(v);

		if(u == v)
			return;
		
		peso[v] += peso[u];
		pai[u] = v;
	}

	int query(int u)
	{
		return peso[find(u)];
	}
};

int main(int argc, char const *argv[])
{
	optimize;

	int N, M, Q;

	while(cin >> N >> M)
	{
		Grafo g(N);

		for (int i = 0, u, v; i < M; ++i)
		{
			cin >> u >> v;
			g.join(u, v);
		}

		cin >> Q;

		cout << g.query(Q) << endl;
	}

	return 0;
}