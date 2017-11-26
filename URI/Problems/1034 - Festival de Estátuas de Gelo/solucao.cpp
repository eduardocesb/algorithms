#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 110
#define MAXM 1000010

using namespace std;

int DP[MAXM];

int nums[MAXN];

int T, N, M;

int solve(int resta)
{
	sort(nums, nums + N + 1);

	DP[0] = 0;

	for (int i = 1; i <= resta; ++i)
		for (int j = 1; j <= N; ++j)
			if(i >= nums[j])
				DP[i] = min(DP[i], 1 + DP[i - nums[j]]);
			else
				break;

	return DP[resta];
}

int main(int argc, char const *argv[])
{
	//optimize;

	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= M; ++i)
			DP[i] = MAXM;

		for (int i = 1; i <= N; ++i)
			scanf("%d", &nums[i]);

		printf("%d\n", solve(M));
	}

	return 0;
}