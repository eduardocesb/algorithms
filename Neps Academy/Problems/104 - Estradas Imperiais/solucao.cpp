//https://neps.academy/problem/104
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll int
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 100020
#define MAXL 18
#define endl '\n'
#pragma g++ optimize("O2")

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

vii grafo[MAXN];
unordered_map<int, int> custo[MAXN];
int N, M, dp[MAXN][MAXL], nivel[MAXN], pai[MAXN], sz[MAXN];

ll maior[MAXN][MAXL], TOTAL;

struct Aresta
{
	int u, v;

	ll c;

	Aresta(int u = 0, int v = 0, ll c = 0) : u(u), v(v), c(c) {}

	bool operator < (const Aresta &a) const
	{
		return c < a.c;
	}
};

vector<Aresta> arestas;

int find(int x)
{
	return pai[x] == x ? x : (pai[x] = find(pai[x]));
}

bool join(int u, int v)
{
	u = find(u);
	v = find(v);

	if(u == v) return false;

	return pai[u] = v;
}


void dfs(int u, int p)
{
	for(auto &x : grafo[u]) if(x.first != p)
	{
		int v = x.first;
		int c = x.second;

		nivel[v] = nivel[u] + 1;

		dp[v][0] = u;
		maior[v][0] = c;
		dfs(v, u);
	}
}

void precalc()
{
	for(int i = 1; i <= N; i++) pai[i] = i;

	sort(ALL(arestas));

	for(auto &a : arestas)
	{
		if(join(a.u, a.v))
		{
			TOTAL += a.c;
			grafo[a.u].EB(a.v, a.c);
			grafo[a.v].EB(a.u, a.c);
		}
	}

	memset(dp, -1, sizeof dp);

	dfs(1, -1);

	for(int i = 1; i < MAXL; i++)
		for(int u = 1; u <= N; u++)
			if(dp[u][i - 1] != -1 && dp[dp[u][i - 1]][i - 1] != -1)
			{
				dp[u][i] = dp[dp[u][i - 1]][i - 1];
				maior[u][i] = max(maior[u][i - 1], maior[dp[u][i - 1]][i - 1]);
			}
}

ll maior_dist(int u, int v)
{
	if(nivel[u] < nivel[v]) swap(u, v);

	ll ans = 0;

	for(int i = MAXL - 1; i >= 0; i--)
	{
		if(dp[u][i] != -1 && nivel[dp[u][i]] >= nivel[v])
		{
			ans = max(ans, maior[u][i]);
			u = dp[u][i];			
		}
	}

	if(u == v)
		return ans;

	for(int i = MAXL - 1; i >= 0; i--)
	{
		if(dp[u][i] != dp[v][i])
		{
			ans = max({ans, maior[u][i], maior[v][i]});

			u = dp[u][i];
			v = dp[v][i];
		}
	}

	ans = max({ans, maior[u][0], maior[v][0]});

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;
	
	cin >> N >> M;

	int Q, u, v, c;

	while(M--)
	{
		cin >> u >> v >> c;

		arestas.EB(u, v, c);

		custo[u][v] = c;
		custo[v][u] = c;
	}

	precalc();

	cin >> Q;

	while(Q--)
	{
		cin >> u >> v;

		cout << (TOTAL + custo[u][v] - maior_dist(u, v)) << endl; 
	}

	return 0;
}