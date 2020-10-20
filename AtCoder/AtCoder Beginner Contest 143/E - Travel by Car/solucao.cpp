//https://atcoder.jp/contests/abc143/tasks/abc143_e
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000020LL
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
#define MAXN 303
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

int N, M, L;

int dp[MAXN][MAXN], fuel[MAXN][MAXN];

void precalc()
{
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				fuel[i][j] = min(fuel[i][j], fuel[i][k] + fuel[k][j]);

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			if(fuel[i][j] <= L)
				dp[i][j] = 1;

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			if(dp[i][j] == INF)
				dp[i][j] = 0;
}

int main(int argc, char const *argv[])
{
	optimize;

	int Q, a, b, c;

	cin >> N >> M >> L;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			dp[i][j] = fuel[i][j] = i == j ? 0 : INF;

	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;

		fuel[a][b] = fuel[b][a] = c;
	}

	precalc();

	cin >> Q;

	while(Q--)
	{
		cin >> a >> b;
		cout << dp[a][b] - 1 << endl;
	}


	return 0;	
} 	