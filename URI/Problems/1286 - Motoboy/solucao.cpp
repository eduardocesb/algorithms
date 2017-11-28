#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 22
#define MAXP 33

using namespace std;

int DP[MAXN][MAXP];
int peso[MAXN];
int beneficio[MAXN];

int solve(int obj, int aguenta)
{
	if(DP[obj][aguenta] != -1)
		return DP[obj][aguenta];

	if(!obj || !aguenta)
		return DP[obj][aguenta] = 0;

	int nao_coloca = solve(obj - 1, aguenta);
	int coloca = 0;

	if(aguenta >= peso[obj])
		coloca = beneficio[obj] + solve(obj - 1, aguenta - peso[obj]);

	return DP[obj][aguenta] = max(coloca, nao_coloca);
}

int main(int argc, char const *argv[])
{
	optimize;

	int N, P;

	while((cin >> N) && N)
	{
		memset(DP, -1, sizeof(DP));

		cin >> P;

		for (int i = 1; i <= N; ++i)
			cin >> beneficio[i] >> peso[i];

		cout << solve(N, P) << " min.\n";
	}

	return 0;
}