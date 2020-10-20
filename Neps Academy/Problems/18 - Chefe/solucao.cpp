//https://neps.academy/problem/18
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

int N, M, I, idade[MAXN], dp[MAXN], tempo, vis[MAXN], pos[MAXN];
vi grafo[MAXN];

int solve(int u, bool ok = false)
{
	if(vis[u] == tempo) return dp[u];

	int ans = ok ? idade[u] : INF;

	for(auto v : grafo[u])
		ans = min(ans, solve(v, true));	

	vis[u] = tempo;

	return dp[u] = ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	int u, v;
	
	cin >> N >> M >> I;

	for(int i = 1; i <= N; i++)
	{
		pos[i] = i;
		cin >> idade[i];
	}


	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;

		grafo[v].PB(u);
	}

	char op;

	while(I--)
	{
		cin >> op >> u;

		if(op == 'T')
		{
			cin >> v;

			swap(idade[pos[u]], idade[pos[v]]);

			swap(pos[u], pos[v]);
		}
		else
		{
			tempo++;

			int ans = solve(pos[u]);

			if(ans == INF)
				cout << "*" << endl;
			else 
				cout << ans << endl;
		}
	}

	return 0;
}