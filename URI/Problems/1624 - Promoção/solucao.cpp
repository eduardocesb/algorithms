#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 110
#define MAXP 120

using namespace std;

int dp[MAXN][MAXP], peso[MAXN], valor[MAXN], N, P;

int solve(int n, int p)
{
	if(n >= N || p <= 0) return 0;
	if(dp[n][p] != -1) return dp[n][p];

	dp[n][p] = solve(n + 1, p);

	if(p >= peso[n])
		dp[n][p] = max(dp[n][p], valor[n] + solve(n + 1, p - peso[n]));

	return dp[n][p];
}


int main(int argc, char const *argv[])
{
	optimize;

	while((cin >> N) && N)
	{
		for(int i = 0; i < N; i++)
			cin >> valor[i] >> peso[i];

		memset(dp, -1, sizeof dp);

		cin >> P;

		cout << solve(0, P) << endl;
	}
	return 0;
}