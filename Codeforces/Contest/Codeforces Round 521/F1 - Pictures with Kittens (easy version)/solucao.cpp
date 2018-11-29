#include <bits/stdc++.h>
#define INFINITO 1000000000000
#define ll long long
#define MAXN 220

using namespace std;

ll dp[MAXN][MAXN][MAXN];
int nums[MAXN];
int N, X, K;
bool ok = true;

ll solve(int i, int x, int k)
{
	if(!x || k < 0) return -INFINITO;
	if(dp[i][x][k] != -1LL) return dp[i][x][k];
	if(i == N) return ok = false;

	ll best = solve(i + 1, X, k - 1) + nums[i];
	best = max(best, solve(i + 1, x - 1, k));

	return dp[i][x][k] = best;
}

int main(int argc, char** argv)
{
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			for(int k = 0; k < MAXN; k++)
				dp[i][j][k] = -1LL;

	cin >> N >> X >> K;

	for(int i = 0; i < N; i++) cin >> nums[i];

	ll r = solve(0, X, K);

	cout << (ok ? -1LL : r) << endl;

	return 0;
}
