#include <bits/stdc++.h>
#define MAXN 300010

using namespace std;

long long dp[MAXN];
int nums[MAXN];

void fastscan(int &number)
{
	bool negative = false;
	register int c;

	number = 0;
	c = getchar();
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		number = number * 10 + c - 48;

	if (negative)
		number *= -1;
}

int main(int argc, char** argv)
{
	int N, S;

	fastscan(N);
	fastscan(S);

	for(int i = 0; i < N; i++)
		fastscan(nums[i]);

	sort(nums, nums + N);

	dp[0] = 1LL * S;

	for(int i = 1; i < N; i++)
		dp[i] = min(dp[i - 1] + S, dp[i - 1] - nums[i - 1] + nums[i]);

	cout << dp[N - 1] << endl;
	return 0;
}
