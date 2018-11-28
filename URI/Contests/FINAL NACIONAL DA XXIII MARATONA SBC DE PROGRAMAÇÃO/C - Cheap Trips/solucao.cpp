#include <bits/stdc++.h>
#define INFINITO 1000000000
#define MAXN 10100

using namespace std;

int N;
int dp[MAXN][120][6];
int duracao[MAXN], custo[MAXN];

int preco(int i, int vez)
{
	if(!vez) return custo[i];
	if(vez < 2) return custo[i] / 2;
	return custo[i] / 4;
}

int solve(int i, int tempo, int vez)
{
	if(i == N) return 0;
	if(dp[i][tempo][vez] != -1) return dp[i][tempo][vez];
	
	int comecar = solve(i + 1, 120, 0);
	int nao_comecar = INFINITO;
	
	if(duracao[i] < tempo && vez < 5)
		nao_comecar = solve(i + 1, tempo - duracao[i], vez + 1);
	
	return dp[i][tempo][vez] = min(comecar, nao_comecar) + preco(i, vez);
}

int main(int argc, char** argv)
{
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> duracao[i] >> custo[i];
		custo[i] *= 4;
	}
	
	memset(dp, -1, sizeof dp);
	
	int r = solve(0, 120, 0);
	
	cout << setprecision(2) << fixed << (r / 4.0) << endl;
	
	return 0;
}