//https://neps.academy/problem/497
//Solution in O(N)

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define MOD 1000000007
#define MAXN 100010
#define MAXL 22

using namespace std;

bool vis[MAXN];

vector<int> grafo[MAXN];

int dfs(int u)
{
	if(vis[u]) return 0;

	vis[u] = true;

	int r = 1;

	for(auto v : grafo[u])
		r += dfs(v);

	return r;
}

int main(int argc, char** argv)
{
	optimize;
	
	int N, A, B, C;

	cin >> N;

	for(int i = 1; i < N; i++)
	{
		cin >> A >> B >> C;

		if(!C) grafo[A].push_back(B), grafo[B].push_back(A);
	}

	ll r = (1LL * N * (N - 1)) / 2LL, sum;

	for(int i = 1; i <= N; i++)
	{
		sum = dfs(i);
		r -= (sum * (sum - 1)) / 2;
	}

	cout << r << endl;

	return 0;
}