#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 200100
#define MAXL 25

using namespace std;

int st[MAXN][MAXL], nums[MAXN], monstro[MAXN], N, M, lg[MAXN];

void precalc()
{
	for (int i = 1; i <= N; i++)
		st[i][0] = nums[i];

	for (int j = 1; j < MAXL; j++)
		for (int i = 1; i + (1 << j) <= N + 1; i++)
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R)
{
	int j = lg[R - L + 1];
	return max(st[L][j], st[R - (1 << j) + 1][j]);
}

int solve()
{
	precalc();

	int r = 1, ant = 0, maior = 0;

	for(int i = 0; i < N; i++)
	{
		int dias = (i - ant) + 1;

		maior = max(maior, monstro[i]);

		if(query(dias, N) < maior)
		{
			ant = i;
			r++;	
			maior = monstro[i];
		}
	}

	return r;
}

int main(int argc, char const *argv[])
{
	optimize;

	lg[1] = 0;
	for (int i = 2; i < MAXN; i++)
		lg[i] = lg[i / 2] + 1;

	int T, x, y;

	cin >> T;

	while(T--)
	{
		cin >> N;

		int m1 = -1, m2 = -1;

		for(int i = 0; i < N; i++)
		{
			cin >> monstro[i];
			m1 = max(m1, monstro[i]);
		}

		cin >> M;

		for(int i = 0; i <= N; i++) nums[i] = 0;

		for(int i = 0; i < M; i++)
		{
			cin >> x >> y;

			m2 = max(m2, x);

			nums[y] = max(nums[y], x);
		}

		cout << ((m2 < m1) ? -1 : solve()) << endl;
	}


	return 0;
}
