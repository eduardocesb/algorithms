//https://www.urionlinejudge.com.br/judge/pt/problems/view/2965
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020
#define all(x) x.begin(), x.end()
#define ll long long
#define pii pair<int,int>
#define PB push_back
#define EB emplace_back
#define MAXN 1000020
#define MAXL 23

using namespace std;

vector<int> grafo[MAXN], pai(MAXN), nums;
int N, K;
bool vis[MAXN];

vector<pii> alturas;

void dfs(int u = 1, int nivel = 0, int p = -1)
{
	pai[u] = p;
	
	alturas.EB(nivel, u);

	for(auto v : grafo[u])
		if(v != p)
			dfs(v, nivel + 1, u);
}

int solve()
{
	int ans = 0;

	dfs();

	sort(all(alturas));
	reverse(all(alturas));

	for(auto x : alturas)
	{
		int qtd = 0, v = x.second;
		while(v != -1 && !vis[v])
		{
			vis[v] = true;
			v = pai[v];
			qtd++;
		}

		nums.push_back(qtd);
	}

	sort(all(nums));
	reverse(all(nums));

	for(int i = 0; i < K; i++)
		ans += nums[i];

	return ans;
}


int main(int argc, char const *argv[])
{
	optimize;

	int x;

	cin >> N >> K;
	
	for(int i = 1; i < N; i++)
	{
		cin >> x;

		grafo[i + 1].PB(x);
		grafo[x].PB(i + 1);
	}

	cout << solve() << endl;

	return 0;
}