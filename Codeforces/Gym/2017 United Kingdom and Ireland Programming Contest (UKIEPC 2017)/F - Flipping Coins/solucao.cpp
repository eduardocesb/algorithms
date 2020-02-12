#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 440

using namespace std;

int N, K;

ld dp[MAXN][MAXN];

ld solve()
{
	dp[0][0] = 1;

	for(int k = 1; k <= K; k++)
		for(int i = 0; i <= N; i++)
		{
			dp[i][k] = dp[i][k - 1] / 2.0;

			if(i)
				dp[i][k] += dp[i - 1][k - 1] / 2.0;

			if(i == N - 1)
				dp[i][k] += dp[i + 1][k - 1] / 2.0;
		}

	ld ans = 0;

	for(int i = 1; i <= N; i++)
		ans += i * dp[i][K];
	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N >> K;

	cout << setprecision(15) << fixed << solve() << endl;
	
	return 0;
}