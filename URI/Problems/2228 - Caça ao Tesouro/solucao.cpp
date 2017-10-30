#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 110

using namespace std;

int X, Y, N;
int DP[MAXN][MAXN * MAXN];
int preco[MAXN];

int solve(int N, int C){

	//Caso já tenha calculado aquele valor...
	if(DP[N][C] != -1) return DP[N][C];
	//Caso não precise de mais nenhum valor...
	if(!C) return DP[N][C] = 1;
	//Caso não tenha mais objetos...
	if(!N) return DP[N][C] = 0;

	int nao_coloca = solve(N - 1, C);

	//Caso eu não precise colocar retorno true...
	if(nao_coloca) return DP[N][C] = 1;

	if(C >= preco[N])
		return DP[N][C] = solve(N - 1, C - preco[N]);

	return DP[N][C] = 0;
}

int main(int argc, char const *argv[])
{
	//optimize;

	int t = 1;

	while(scanf("%d %d %d", &X, &Y, &N) && (X || Y || N)){

		memset(DP, -1, sizeof(DP));

		int s = 0;

		for (int i = 1; i <= N; s += (preco[i++]))
			scanf("%d", &preco[i]);

		printf("Teste %d\n", t++);
		if((X + Y + s) % 2)
			printf("N\n");
		else
			if(solve(N, ((X + Y + s) / 2) - X))
				printf("S\n");
			else
				printf("N\n");
		printf("\n");
	}
	return 0;
}