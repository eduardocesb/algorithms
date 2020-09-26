#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 200020
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = 2.0 * acos(0.0);
const int BLOCK = 333;

int N, A, B, dp[MAXN][MAXL], nivel[MAXN], peso[MAXN];
vii grafo[MAXN];

void dfs(int u = 1, int p = 0, int c = 0)
{
	dp[u][0] = p;
	nivel[u] = nivel[p] + 1;
	peso[u] = peso[p] + c;

	for(auto x : grafo[u]) if(x.first != p)
		dfs(x.first, u, x.second);
}

void precalc()
{
	memset(dp, -1, sizeof dp);

	dfs();

	for(int i = 1; i < MAXL; i++)
		for(int u = 1; u <= N; u++)
			if(dp[u][i - 1] != -1)
				dp[u][i] = dp[dp[u][i - 1]][i - 1];
}

int LCA(int u, int v)
{
	if(nivel[u] < nivel[v]) swap(u, v);

	for(int i = MAXL - 1; i >= 0; i--)
		if(dp[u][i] != -1 && nivel[dp[u][i]] >= nivel[v])
			u = dp[u][i];

	if(u == v) return u;

	for(int i = MAXL - 1; i >= 0; i--)
		if(dp[u][i] != dp[v][i])
		{
			u = dp[u][i];
			v = dp[v][i];
		}

	return dp[u][0];
}

int dist(int u, int v)
{
	return peso[u] + peso[v] - 2 * peso[LCA(u, v)];
}

int main(int argc, char const *argv[])
{
	optimize;
	
	cin >> N >> A >> B;

	int u, v, c;

	for(int i = 1; i < N; i++)
	{
		cin >> u >> v >> c;

		grafo[u].EB(v, c);
		grafo[v].EB(u, c);
	}

	precalc();

	cout << dist(A, B) << endl;

	return 0;
}