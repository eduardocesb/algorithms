#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int dp[MAXN], N, M;
vector<int> moedas;

int troco(int falta){
	if(falta == 0) return 1;
	if(dp[falta] != -1) return dp[falta];

	for (int i = 0; i < N; ++i)
	{
		if(falta - moedas[i] >= 0)
			if(troco(falta - moedas[i])) return dp[falta - moedas[i]] = 1;
	}

	return dp[falta] = 0;
}

int main(int argc, char const *argv[])
{
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;

	for (int x, i = 0; i < N; ++i)
	{
		cin >> x;
		moedas.push_back(x);
	}
	int r = 0;
	for (int i = 1; i < M; ++i){
		if(dp[i] == 0) r++;
		else if(dp[i] == -1 && troco(i) == 0) r++;
	}

	cout << r << endl;
	return 0;
}