#include <bits/stdc++.h>
#define MAXN 1010
#define INFINITO 1000000
using namespace std;

int dp[MAXN], N, M;
vector<int> moedas;

int troco(int falta){
	if(falta == 0) return 0;
	if(dp[falta] != INFINITO) return dp[falta];
	for (int i = 0; i < N; ++i)
	{
		if(falta - moedas[i] >= 0)
			dp[falta] = min(dp[falta], 1 + troco(falta - moedas[i]));
	}

	return dp[falta];
}

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	for (int i = 0; i <= M; ++i) dp[i] = INFINITO;
	for (int x, i = 0; i < N; ++i)
	{
		cin >> x;
		moedas.push_back(x);
	}

	cout << (troco(M) < 10 ? 'S' : 'N') << endl;
	return 0;
}