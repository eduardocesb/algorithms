#include <bits/stdc++.h>
#define INFINITO 1000000000
#define MAXN 110

using namespace std;

int DP[MAXN][MAXN];
int N;

int max_sum()
{
	int r = -INFINITO;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++)
			for(int k = i; k <= N; k++) for(int l = j; l <= N; l++)
					r = max(r, DP[k][l] - DP[i - 1][l] - DP[k][j - 1] + DP[i - 1][j - 1]);
	return r;
}

int main(int argc, char** argv)
{
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> DP[i][j];
			DP[i][j] += DP[i - 1][j];
			DP[i][j] += DP[i][j - 1];
			DP[i][j] -= DP[i - 1][j - 1];
		}
	}

	cout << max_sum() << endl;
	return 0;
}
