#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 55
#define MAXP 110

using namespace std;

int DP[MAXN][MAXP];
int peso[MAXN];
int beneficio[MAXN];
int N;

int solve(int obj, int aguenta)
{
	if(DP[obj][aguenta] != -1)
		return DP[obj][aguenta];

	if(obj == N || !aguenta)
		return DP[obj][aguenta] = 0;

	int nao_coloca = solve(obj + 1, aguenta);
	int coloca = 0;

	if(aguenta >= peso[obj])
		coloca = beneficio[obj] + solve(obj + 1, aguenta - peso[obj]);

	return DP[obj][aguenta] = max(coloca, nao_coloca);
}

int main(int argc, char const *argv[])
{
	optimize;

	int T, K, R;

	cin >> T;

	for(int t = 0; t < T; t++)
	{
		cin >> N;

		memset(DP, -1, sizeof DP);

		for (int i = 0; i < N; ++i)
			cin >> beneficio[i] >> peso[i];

		cin >> K >> R;

		cout << (solve(0, K)  >= R ? "Missao completada com sucesso" : "Falha na missao") << endl;
	}

	return 0;
}