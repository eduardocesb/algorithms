#include <bits/stdc++.h>
#define MAXN 1000000
#define ull unsigned long long

using namespace std;

ull dp[MAXN];

ull fat(int x){
	if(x < 2) return 1;
	if(dp[x] != -1) return dp[x];
	return dp[x] = x * fat(x - 1);
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < MAXN; ++i) dp[i] = -1;

	int N, M;
	while((cin >> N >> M)){
		cout << fat(N) + fat(M) << endl;
	}
	return 0;
}