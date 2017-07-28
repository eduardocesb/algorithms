#include <bits/stdc++.h>
#define MAXN 510
#define MAXS 5010

using namespace std;

int valor[6], notas[] = {2, 5, 10, 20, 50, 100};
long long int dp[MAXS][MAXN];

long long int troco(int resta, int tipo = 0){
	if(resta == 0) return 1LL;
	if(resta < 0 || tipo > 5) return 0LL;
	if(dp[resta][tipo] != -1) return dp[resta][tipo];
	long long int soma = 0LL;
	for(int i = 0; i <= valor[tipo]; i++){
		if(resta < i * notas[tipo]) break;
		soma += troco(resta - (i * notas[tipo]), tipo + 1);
	}

	return dp[resta][tipo] = soma;
}

int main(int argc, char const *argv[])
{
	memset(dp, -1, sizeof(dp));
	int S;
	cin >> S;
	for (int i = 0; i < 6; ++i)
		cin >> valor[i];

	cout << troco(S) << endl;
	return 0;
}