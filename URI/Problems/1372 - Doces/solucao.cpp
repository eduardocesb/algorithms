#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;

int N, M, dp[MAXN], linha[MAXN], best[MAXN];

vector<vi> nums;

int calc(int i, int j = 0)
{
	if(j >= M) return 0;
	if(~best[j]) return best[j];

	return best[j] = max(calc(i, j + 1), nums[i][j] + calc(i, j + 2));
}

int f(int i)
{
	if(~linha[i]) return linha[i];

	for(int j = 0; j < M; j++)
		best[j] = -1;

	return linha[i] = calc(i);
}

int solve(int i)
{
	if(i >= N) return 0;
	if(~dp[i]) return dp[i];

	return dp[i] = max(solve(i + 1), f(i) + solve(i + 2));
}

int main(int argc, char** argv)
{
	optimize;

	while((cin >> N >> M) && (N + M))
	{
		nums.resize(N);

		for(int i = 0; i < N; i++)
		{
			dp[i] = -1;

			nums[i].resize(M);

			for(int &num : nums[i])
				cin >> num;
		}

		for(int i = 0; i < M; i++) linha[i] = -1;

		cout << solve(0) << endl;
	}

	return 0;
}