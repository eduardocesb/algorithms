#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXQ 200200
#define MAXN 30300

using namespace std;

struct Query
{
	int l, r, k, i;

	bool operator < (Query &x)
	{
		return k < x.k;
	}
};

struct Elemento
{
	int val, i;

	bool operator < (Elemento &x)
	{
		return val < x.val;
	}
};

int bit[MAXN];
int N, Q;
Elemento nums[MAXN];
Query queries[MAXQ];

void add(int i)
{
	for(; i <= N; i += i & -i)
		bit[i]++;
}

int query(int i)
{
	int r = 0;
	for(; i > 0; i -= i & -i)
		r += bit[i];
	return r;
}

void solve()
{
	memset(bit, 0, sizeof bit);
	int r[Q];
	sort(queries + 1, queries + Q + 1);
	sort(nums + 1, nums + N + 1);

	int davez = 1;

	for(int i = 1; i <= Q; i++)
	{
		while(nums[davez].val <= queries[i].k && davez <= N)
			add(nums[davez++].i);

		int tam = (queries[i].r - queries[i].l) + 1;
		r[queries[i].i] = tam - (query(queries[i].r) - query(queries[i].l - 1));
	}

	for(int i = 1; i <= Q; i++)
		printf("%d\n", r[i]);
}

int main(int argc, char** argv)
{
	optimize;

	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &nums[i].val);
		nums[i].i = i;
	}

	scanf("%d", &Q);

	for(int i = 1; i <= Q; i++)
	{
		scanf("%d %d %d", &queries[i].l, &queries[i].r, &queries[i].k);
		queries[i].i = i;
	}

	solve();

	return 0;
}
