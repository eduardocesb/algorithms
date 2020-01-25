//https://www.spoj.com/problems/TAP2016C/

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 50500

using namespace std;

vector<int> grafo[MAXN];
int N, M, grau[MAXN], nums[MAXN], ans;
bool ok[MAXN];

void process(int u)
{
	ans++;

	for(auto v : grafo[u])
	{
		grau[v]--;
		if(ok[v] && !grau[v])
			process(v);
	}
}

void solve()
{
	ans = 0;

	for(int i = 1; i <= N; i++)
	{
		ok[nums[i]] = true;
		if(!grau[nums[i]])
			process(nums[i]);

		cout << ans << endl;
	}
}

void reset(int N)
{
	for(int i = 0; i <= N; i++)
	{
		ok[i] = false;
		grafo[i].clear();
		grau[i] = 0;
	}
}

int main(int argc, char const *argv[])
{
	optimize;

	int u, v;

	while(!cin.eof() && (cin >> N >> M))
	{
		reset(N);

		for(int i = 0; i < M; i++)
		{
			cin >> u >> v;
			grafo[u].push_back(v);
			grau[v]++;
		}

		for(int i = 1; i <= N; i++) cin >> nums[i];

		solve();
	}

	return 0;
}