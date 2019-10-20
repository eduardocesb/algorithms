//https://www.spoj.com/problems/IITWPC4I/
//Solved with DSU

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define MAXN 100010

using namespace std;

struct Aresta
{
	int A, B, C;

	Aresta(int a, int b, int c)
	{
		A = a;
		B = b;
		C = c;
	}

	bool operator < (Aresta &a) const
	{
		return C < a.C;
	}
};

vector<Aresta> arestas;
int N, M, milk[MAXN], pai[MAXN];
ll ans;

int find(int x)
{
	return pai[x] == -1 ? x : pai[x] = find(pai[x]);
}

int join(Aresta x)
{
	int u = x.A;
	int v = x.B;
	int c = x.C;

	u = find(u);
	v = find(v);

	if((u == v) or (milk[u] && milk[v])) return 0;

	if(milk[u] or milk[v])
		milk[v] = true;

	pai[u] = v;

	return c;
}

void reset()
{
	ans = 0LL;
	memset(pai, -1, sizeof pai);
	arestas.clear();
}

int main(int argc, char const *argv[])
{
	optimize;

	int A, B, C, T;

	cin >> T;

	while(T--)
	{
		reset();

		cin >> N >> M;

		for(int i = 1; i <= N; i++) cin >> milk[i];

		for(int i = 0; i < M; i++)
		{
			cin >> A >> B >> C;
			arestas.push_back(Aresta(A, B, C));
		}

		sort(arestas.begin(), arestas.end());

		for(Aresta x : arestas)
			ans += join(x);

		bool ok = true;

		for(int i = 1; i <= N; i++) ok *= milk[find(i)];

		if(ok)
			cout << ans << endl;
		else
			cout << "impossible" << endl;
	}

	return 0;
}