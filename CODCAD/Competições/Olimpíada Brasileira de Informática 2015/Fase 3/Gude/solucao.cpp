#include <bits/stdc++.h>
#define MAXN 300010

using namespace std;

long long dp[MAXN];
int nums[MAXN];

int main(int argc, char** argv)
{
	int N, S;

	cin >> N >> S;


	for(int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums, nums + N);

	dp[0] = 1LL * S;

	for(int i = 1; i < N; i++)
		dp[i] = min(dp[i - 1] + S, dp[i - 1] - nums[i - 1] + nums[i]);

	cout << dp[N - 1] << endl;
	return 0;
}
