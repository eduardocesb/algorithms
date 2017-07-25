#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int dp[MAXN], N, M;
vector<int> moedas;

bool troco(int x){
	if(x < 0) return false;
	if(x == 0) return true;

	for (int i = 0; i < N; ++i)
		if(troco(x - moedas[i])) return dp[x - moedas[i]] = true;
	return dp[x] = false;
}


int main(int argc, char const *argv[])
{
	cin >> N >> M;
	for (int x, i = 0; i < N; ++i)
	{
		cin >> x;
		moedas.push_back(x);
	}

	cout << (troco(M) ? 'S' : 'N') << endl;
	return 0;
}