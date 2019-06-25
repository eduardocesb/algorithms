#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 1010
#define MAXE 330

using namespace std;

int dp[MAXE][MAXN], enfeite[MAXE], peso[MAXN], E, P;

int solve(int e, int p)
{
	if(e >= E || p <= 0) return 0;
	if(dp[e][p] != -1) return dp[e][p];

	int best = 0;

	if(p >= peso[e])
		best = enfeite[e] + solve(e + 1, p - peso[e]);

	return dp[e][p] = max(best, solve(e + 1, p));
}

int main(int argc, char const *argv[])
{
	optimize;

	int T;

	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> E >> P;

		for(int j = 0; j < E; j++)
			cin >> enfeite[j] >> peso[j];

		memset(dp, -1, sizeof dp);

		cout << "Galho " << i << ":" << endl << "Numero total de enfeites: " << solve(0, P) << endl << endl;
	}

	return 0;
}