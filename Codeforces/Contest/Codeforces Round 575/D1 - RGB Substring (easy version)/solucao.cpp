#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 200020

using namespace std;

int a[MAXN], b[MAXN], c[MAXN], Q, N, K, pos;

int solve(int nums[])
{
	int sum = 0, best = 0;

	for(int i = 0; i < N; i++)
	{
		sum += nums[i];

		if(i >= K) sum -= nums[i - K];

		best = max(best, sum);
	}

	return best;
}

int main(int argc, char** argv)
{
	optimize;

	cin >> Q;

	while(Q--)
	{
		cin >> N >> K;

		char x;
		string RGB = "RGBRGB";

		for(int i = 0; i < N; i++)
		{
			cin >> x;

			pos = i % 3;

			a[i] = x == RGB[pos];
			b[i] = x == RGB[pos + 1];
			c[i] = x == RGB[pos + 2];
		}

		cout << max(0, K - max(solve(a), max(solve(b), solve(c)))) << endl;
	}

	return 0;
}
