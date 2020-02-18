//https://codeforces.com/contest/1304/problem/E
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 1000020
#define MAXL 23

using namespace std;

vector<int> grafo[MAXN];
int dp[MAXN][MAXL], nivel[MAXN];
int N, X, Y, A, B, K;

void dfs(int u = 1, int pai = -1)
{
	for(auto v : grafo[u])
		if(v != pai)
		{
			nivel[v] = nivel[u] + 1;
			dp[v][0] = u;
			dfs(v, u);
		}
}

void precalc()
{
	memset(dp, -1, sizeof dp);

	nivel[1] = 0;
	dfs();

	for(int j = 1; j < MAXL; j++)
		for(int i = 1; i <= N; i++)
			if(dp[i][j - 1] != -1)
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
}

int LCA(int u, int v)
{
	if(nivel[u] < nivel[v]) swap(u, v);

	for(int j = MAXL - 1; j >= 0; j--)
	{
		if(dp[u][j] != -1 && nivel[v] <= nivel[dp[u][j]])
			u = dp[u][j];
	}

	if(u == v) return u;

	for(int j = MAXL - 1; j >= 0; j--)
	{
		if(dp[u][j] != -1 && dp[u][j] != dp[v][j])
		{
			u = dp[u][j];
			v = dp[v][j];
		}
	}

	return dp[u][0];
}


int dist(int u, int v)
{
	return nivel[u] + nivel[v] - (2 * nivel[LCA(u, v)]);
}

bool solve()
{
	int d =  dist(A, B);
	int x = dist(X, A);
	int y = dist(Y, B);
	int z = dist(X, B);
	int w = dist(Y, A);

	if(K >= d && ((K & 1) == (d & 1))) return true;
	if(K >= (x + y + 1) && ((K & 1) == ((x + y + 1) & 1))) return true;
	if(K >= (z + w + 1) && ((K & 1) == ((z + w + 1) & 1))) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	optimize;

	int u, v, Q;

	cin >> N;

	for(int i = 1; i < N; i++)
	{
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	precalc();

	cin >> Q;

	while(Q--)
	{
		cin >> X >> Y >> A >> B >> K;

		cout << (solve() ? "YES" : "NO") << endl;
	}

	return 0;
}