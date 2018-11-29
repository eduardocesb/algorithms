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

	for(int i = 1; i <= N; i++)
		sparse[i][0] = nums[i];

	for(int j = 1; j <= logs[N]; j++)
		for(int i = 1; i <= N; i++)
			sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
	int k = logs[r - l + 1];
	return max(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}

int main(int argc, char** argv)
{
	optimize;
	int M, L, R;

	cin >> N >> M;

	for(int i = 1; i <= N; i++) cin >> nums[i];

	build();

	int r = 0;

	while(M--)
	{
		cin >> L >> R;
		
		r += nums[L] >= query(L, R - 1);
	}

	cout << r << endl;
	return 0;
}
