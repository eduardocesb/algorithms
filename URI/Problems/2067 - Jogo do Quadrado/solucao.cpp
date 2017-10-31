#include <bits/stdc++.h>
#define MAXN 220
#define INFINITO 300

using namespace std;

int N, M;
int DP[MAXN][MAXN];
unordered_map<int, bool> da_certo;

int main(int argc, char const *argv[])
{
	int x;

	scanf("%d %d", &N, &M);

	//Primeira linha e primeira coluna são nulas...
	for (int i = 0; i <= N; ++i)
		DP[i][0] = 0;

	for (int i = 0; i <= M; ++i)
		DP[0][i] = 0;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if(scanf("%d", &x) && x){
				DP[i][j] = 1 + min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1]));
				da_certo[DP[i][j]] = true;
			}

	int Q;

	scanf("%d", &Q);

	for (int i = 0; i < Q; ++i)
		if(scanf("%d", &x) && da_certo[x])
			printf("yes\n");
		else
			printf("no\n");
	return 0;
}