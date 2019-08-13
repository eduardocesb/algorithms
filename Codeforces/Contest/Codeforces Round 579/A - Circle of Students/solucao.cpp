#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 440

using namespace std;

int nums[MAXN];

bool solve(int i, int N)
{
	if(N == 1) return true;
	
	int diff = nums[i + 1] - nums[i];
	if(diff != 1 && diff != -1) return false;
	for(int j = i + 1; j < (i + N) - 1; j++)
		if(nums[j + 1] - nums[j] != diff) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	optimize;

	int Q, N;

	scanf("%d", &Q);

	while(Q--)
	{
		scanf("%d", &N);

		for(int i = 0; i < N; i++)
		{
			scanf("%d", &nums[i]);
			nums[i + N] = nums[i];
		}

		bool ok = false;

		for(int i = 0; i < N; i++)
		{
			if(solve(i, N))
			{
				ok = true;
				break;
			}
		}

		printf("%s\n", (ok ? "YES" : "NO"));
	}
	
	return 0;
}