#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define MAXN 100010
#define INF 1000000000

using namespace std;

int N, nums[MAXN], C, T;

inline bool ok(long long tamanho)
{
	int sum = 0, caras = 1;

	for(int i = 0; i < N; i++)
	{
		if(nums[i] > tamanho) return false;

		sum += nums[i];

		if(sum > tamanho)
		{
			sum = nums[i];
			caras++;
		}
	}

	return caras <= C;
}

int solve()
{
	int l = 0, r = INF, m, resp = INF;

	while(l <= r)
	{
		m = (l + r) / 2;

		if(ok(1LL * T * m))
		{
			resp = m;
			r = m - 1;
		}
		else 
			l = m + 1;
	}

	return resp;
}

int main(int argc, char const *argv[])
{
	optimize;

	// cin >> N >> C >> T;
	scanf("%d %d %d", &N, &C, &T);

	for(int i = 0; i < N; i++) 
		scanf("%d", &nums[i]);
		// cin >> nums[i];

	printf("%d\n", solve());
	// cout << solve() << endl;
	
	return 0;
}