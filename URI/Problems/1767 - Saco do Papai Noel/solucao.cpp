#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 110
#define MAXP 55

using namespace std;

int dp[MAXN][MAXP], qtd[MAXN][MAXP], r_peso[MAXN][MAXP], N, P, peso[MAXN], quantidade[MAXN];

int solve(int n, int p)
{
	if(n >= N || p <= 0) return 0;
	if(dp[n][p] != -1) return dp[n][p];

	dp[n][p] = solve(n + 1, p);
	qtd[n][p] = qtd[n + 1][p];
	r_peso[n][p] = r_peso[n + 1][p];

	int best = 0;

	if(peso[n] <= p)
		best = quantidade[n] + solve(n + 1, p - peso[n]);

	if(best > dp[n][p])
	{
		dp[n][p] = best;
		qtd[n][p] = 1 + qtd[n + 1][p - peso[n]];
		r_peso[n][p] = peso[n] + r_peso[n + 1][p - peso[n]];
	}

	return dp[n][p];
		
}

int main(int argc, char const *argv[])
{
	optimize;

	int T;

	cin >> T;

	while(T--)
	{
		cin >> N;

		for(int i = 0; i < N; i++)
			cin >> quantidade[i] >> peso[i];

		for(int i = 0; i < MAXN; i++)
			for(int j = 0; j < MAXP; j++)
			{
				r_peso[i][j] = 0;
				dp[i][j] = -1;
				qtd[i][j] = 0;
			}

		cout << solve(0, 50) << " brinquedos" << endl;
		cout << "Peso: " << r_peso[0][50] << " kg" << endl;
		cout << "sobra(m) " << N - qtd[0][50] << " pacote(s)" << endl << endl;
	}

	return 0;
}