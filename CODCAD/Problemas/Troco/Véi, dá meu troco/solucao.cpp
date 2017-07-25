#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int dp[MAXN], N, M;
vector<int> moedas;

bool troco(int x){
	if(x < 0) return 0;
	if(x == 0) return 1;
	if(dp[x] > -1) return dp[x];
	for (int i = 0; i < N; ++i)
		if(troco(x - moedas[i])) return dp[x - moedas[i]] = 1;
	return dp[x] = 0;
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

	cout << (troco(M) ? 'S' : 'N') << endl;
	return 0;
}