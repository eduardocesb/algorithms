#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int dp[MAXN][MAXN][2], nums[MAXN], N;

int solve(int i, int j, int p)
{
	if(dp[i][j][p] != -1) return dp[i][j][p];
	if(i == j) return dp[i][j][p] = p ? nums[i] : 0;
	if(i > j) return 0;

	return dp[i][j][p] = (p ? max(solve(i + 1, j, 0) + nums[i], solve(i, j - 1, 0) + nums[j]) : min(solve(i, j - 1, 1), solve(i + 1, j, 1)));
}

int main(int argc, char** argv)
{
	memset(dp, -1, sizeof dp);

	cin >> N;

	int s = 0;

	for(int i = 1; i <= N; i++)
	{
		cin >> nums[i];
		s += nums[i];
	}

	int r = solve(1, N, 1);

	cout << r << " " << (s - r) << endl;
	return 0;
}