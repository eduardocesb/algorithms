#include <bits/stdc++.h>
#define MAXN 1010
#define MAXM 33

using namespace std;

int T, N, M;
int DP[MAXN][MAXM];
int peso[MAXN], valor[MAXN];

int Knapsack(int obj, int aguenta){
	if(DP[obj][aguenta] != -1) return DP[obj][aguenta];
	if(obj == N || !aguenta) return 0;

	int nao_coloca = Knapsack(obj + 1, aguenta);

	if(peso[obj] <= aguenta)
		return DP[obj][aguenta] = max(nao_coloca, Knapsack(obj + 1, aguenta - peso[obj]) + valor[obj]);

	return DP[obj][aguenta] = nao_coloca;
}

int main(int argc, char const *argv[])
{
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		memset(DP, -1, sizeof(DP));

		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> valor[i] >> peso[i];

		int r = 0, x;

		cin >> M;

		for (int i = 0; i < M; ++i){
			cin >> x;
			r += Knapsack(0, x);
		}

		cout << r << endl;
	}
	return 0;
}