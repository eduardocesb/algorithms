#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 2020
#define MAXL 22

using namespace std;

pii cidades[MAXN], arestas_[MAXN];
int C[MAXN], K[MAXN], N, pai[MAXN], qtd_estacao;
bool estacao[MAXN];

struct Aresta
{
	int U, V;
	ll C;

	Aresta(int u = 0, int v = 0, ll c = 0LL) : U(u), V(v), C(c) {}
	bool operator < (const Aresta &a) const
	{
		return C < a.C;
	}
};

vector<Aresta> arestas;

int find(int x)
{
	return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int u, int v)
{
	u = find(u);
	v = find(v);

	if(u == v) return;

	if(C[u] < C[v])
	{
		pai[v] = u;
		estacao[v] = false;
	}
	else
	{
		pai[u] = v;
		estacao[u] = false;
	}

}

ll solve()
{
	ll ans = 0LL;

	for(int i = 0; i < N; i++)
	{
		pai[i] = i;
		estacao[i] = true;
		for(int j = 0; j < N; j++)
			if(i != j)
				arestas.push_back(Aresta(i, j, 1LL * (K[i] + K[j]) * (abs(cidades[i].first - cidades[j].first) + abs(cidades[i].second - cidades[j].second))));
	}

	sort(arestas.begin(), arestas.end());

	int tam = arestas.size(), u, v, tam_arestas = 0;
	ll c;

	for(int i = 0; i < tam; i++)
	{
		u = find(arestas[i].U);
		v = find(arestas[i].V);
		c = arestas[i].C;

		if(u == v) continue;

		if(c < max(C[u], C[v]))
		{
			arestas_[tam_arestas++] = pii(arestas[i].U + 1, arestas[i].V + 1);
			join(u, v);
			ans += c;
		}
	}

	qtd_estacao = N - tam_arestas;

	for(int i = 0; i < N; i++) ans += estacao[i] * C[i];

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N;

	int x, y;

	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		cidades[i] = pii(x, y);
	}

	for(int i = 0; i < N; i++) cin >> C[i];
	for(int i = 0; i < N; i++) cin >> K[i];

	cout << solve() << endl;

	cout << qtd_estacao << endl;

	for(int i = 0; i < N; i++)
		if(estacao[i]) cout << i + 1 << " ";

	if(qtd_estacao) cout << endl;

	if(qtd_estacao == N) cout << 0 << endl;
	else
	{
		x = N - qtd_estacao;

		cout << x << endl;

		for(int i = 0; i < x; i++)
			cout << arestas_[i].first << " " << arestas_[i].second << endl;
	}

	return 0;
}
