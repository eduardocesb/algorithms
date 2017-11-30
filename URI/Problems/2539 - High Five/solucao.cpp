#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int bit[MAXN];
int N;

void add(int pos, int val)
{
	for(; pos <= N; pos += (pos & -pos))
		bit[pos] += val;
}

int get(int pos)
{
	int r = 0;

	for (; pos; pos -= (pos & -pos))
		r += bit[pos];

	return r;
}

int main(int argc, char const *argv[])
{
	int x;

	while(scanf("%d", &N) == 1)
	{
		memset(bit, 0, sizeof(bit));

		long long r = 0;

		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &x);

			r += get(x);

			add(x, 1);
		}

		printf("%lld\n", r);
	}

	return 0;
}