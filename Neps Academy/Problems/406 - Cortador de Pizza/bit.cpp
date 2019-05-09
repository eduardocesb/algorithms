#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int bit[MAXN];

struct Query
{
	int x, y;

	bool operator < (const Query &a) const
	{
		return x < a.x;
	}
};

bool comp(Query &a, Query &b)
{
	return a.y < b.y;
}

void add(int idx)
{
	for(; idx > 0; idx -= (idx & -idx))
		bit[idx]++;
}

int query(int idx)
{
	int r = 0;
	for(; idx < MAXN; idx += (idx & -idx))
		r += bit[idx];
	return r;
}

int main(int argc, char** argv)
{
	int N, M;

	scanf("%d %d", &N, &M);
	scanf("%d %d", &N, &M);

	Query queries[MAXN];

	map<int, int> compress;

	int i;
	
	long long int r = 1LL;

	for(i = 0; i < N; i++)
	{
		scanf("%d %d", &queries[i].x, &queries[i].y);
		compress[queries[i].y] = 0;
	}

	sort(queries, queries + N, comp);

	i = 1;

for(auto x : compress)
		compress[x.first] = i++;

	sort(queries, queries + N);

	for(i = 0; i < N; i++)
	{
		int idx = compress[queries[i].y];

		int k = query(idx);
		// printf("idx = %d | k = %d\n", idx, k);

		r += k + 1;
		add(idx);
	}

	// printf("%d\n", r);
	memset(bit, 0, sizeof(bit));
	compress.clear();

	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &queries[i].x, &queries[i].y);
		compress[queries[i].y] = 0;
	}

	sort(queries, queries + M, comp);

	i = 1;

for(auto x : compress)
		compress[x.first] = i++;

	sort(queries, queries + M);

	for(i = 0; i < M; i++)
	{
		int idx = compress[queries[i].y];

		int k = query(idx);

		// printf("idx = %d | k = %d\n", idx, k);

		r += N + k + 1;
		add(idx);
	}

	printf("%lld\n", r);

	return 0;
}
