#include <bits/stdc++.h>
#define MAXN 2010

using namespace std;

int valor[MAXN], peso[MAXN], dp[MAXN][MAXN];
int P, N;

long knapsack(int obj, int aguenta){
	if(dp[obj][aguenta] != -1) return dp[obj][aguenta];
	if(obj == N || !aguenta) return 0;

	long nao_coloca = knapsack(obj + 1, aguenta);
	if(peso[obj] <= aguenta){
		long coloca = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);
		return dp[obj][aguenta] = max(nao_coloca, coloca);
	}
	return dp[obj][aguenta] = nao_coloca;
}

int main(int argc, char const *argv[])
{
	cin >> P >> N;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; ++i)
	{
		cin >> peso[i] >> valor[i];
	}

	cout << knapsack(0, P) << endl;
	return 0;
}