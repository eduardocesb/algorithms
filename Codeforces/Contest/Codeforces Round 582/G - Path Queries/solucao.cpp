//https://codeforces.com/contest/1213/problem/G

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 200020


using namespace std;

int pai[MAXN], filhos[MAXN];

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

ll ans;

int find(int x)
{
	return pai[x] == -1 ? x : pai[x] = find(pai[x]); 
}

void join(int u, int v)
{
	u = find(u);
	v = find(v);

	if(u == v) return;

	ans += 1LL * filhos[u] * filhos[v];

	pai[u] = v;
	filhos[v] += filhos[u];
}

int N, M;

ll resp[MAXN];

vector<Aresta> arestas;
vector<pii> queries;

void solve()
{
	for(int i = 1; i <= N; i++) filhos[i] = 1, pai[i] = -1;

	sort(arestas.begin(), arestas.end());
	sort(queries.begin(), queries.end());

	int a = 0;

	for(auto q : queries)
	{
		while(a < N - 1 && arestas[a].C <= q.first) join(arestas[a].A, arestas[a].B), a++;

		resp[q.second] = ans;
	}
}

int main(int argc, char const *argv[])
{
	optimize;

	int A, B, C;

	cin >> N >> M;

	for(int i = 1; i < N; i++)
	{
		cin >> A >> B >> C;
		arestas.push_back(Aresta(A, B, C));
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> C;
		queries.push_back(pii(C, i));	
	}

	solve();

	for(int i = 0; i < M; i++)
		cout << resp[i] << " ";
	cout << endl;

	return 0;
}