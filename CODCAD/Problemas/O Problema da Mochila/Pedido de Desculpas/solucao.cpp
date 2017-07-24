#include <bits/stdc++.h>
#define MAXN 1001

using namespace std;

int C, F, peso[MAXN], valor[MAXN], dp[MAXN][MAXN];

long knapsack(int obj, int aguenta){
	if(dp[obj][aguenta] != -1) return dp[obj][aguenta];
	if(obj == F || !aguenta) return 0;

	long nao_coloca = knapsack(obj + 1, aguenta);

	if(peso[obj] <= aguenta){
		long coloca = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);
		return dp[obj][aguenta] = max(coloca, nao_coloca);
	}
	return dp[obj][aguenta] = nao_coloca;
}


int main(int argc, char const *argv[])
{
	int teste = 1;
	while((cin >> C >> F) && (C != 0 || F != 0)){
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < F; ++i)
		{
			cin >> peso[i] >> valor[i];
		}

		cout << "Teste " << teste++ << endl;
		cout << knapsack(0, C) << endl;
		cout << endl;
	}
	return 0;
}