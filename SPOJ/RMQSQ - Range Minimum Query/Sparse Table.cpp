#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 200200
#define MAXL 20

using namespace std;

int sparse[MAXN][MAXL];
int nums[MAXN], logs[MAXN], N;

void build()
{
	logs[1] = 0;

	for(int i = 2; i < MAXN; i++)
		logs[i] = logs[i >> 1] + 1;

	for(int i = 0; i < N; i++)
		sparse[i][0] = nums[i];

	for(int j = 1; j <= logs[N]; j++)
		for(int i = 0; i < N; i++)
			sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
	int k = logs[r - l + 1];
	return min(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}

int main(int argc, char** argv)
{
	optimize;
	int Q, l, r;

	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> nums[i];

	build();

	cin >> Q;

	while(Q--)
	{
		cin >> l >> r;
		cout << query(l, r) << endl;
	}

	return 0;
}
