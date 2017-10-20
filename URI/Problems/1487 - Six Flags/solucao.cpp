#include <bits/stdc++.h>
#define MAXN 110
#define MAXT 660

using namespace std;
	
int N, T;
int DP[MAXN][MAXT];
int peso[MAXN], beneficio[MAXN];

int Knapsack(int i, int aguenta){
	if(DP[i][aguenta] != -1) return DP[i][aguenta];
	if(i == N || !aguenta) return 0;

	int nao_coloca = Knapsack(i + 1, aguenta);

	if(aguenta >= peso[i])
		return DP[i][aguenta] = max(nao_coloca, Knapsack(i, aguenta - peso[i]) + beneficio[i]);

	return DP[i][aguenta] = nao_coloca;
}

int main(int argc, char const *argv[])
{
	int t = 1;
	while((cin >> N >> T) && (N || T)){

		memset(DP, -1, sizeof(DP));

		for (int i = 0; i < N; ++i)
			cin >> peso[i] >> beneficio[i];

		cout << "Instancia " << t++ << endl;
		cout << Knapsack(0, T) << endl << endl;

	}
	return 0;
}