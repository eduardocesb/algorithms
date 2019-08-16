#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 1010


using namespace std;

vector<int> grafo[MAXN];
bool visitados[MAXN];

void reset()
{
	for(int i = 0; i < MAXN; i++)
	{
		grafo[i].clear();
		visitados[i] = false;
	}

}

pii le()
{
	char x;
	int u, v;
	cin >> x >> u >> x >> v >> x;

	return pii(u, v);
}

void addAresta(int u, int v)
{
	grafo[u].push_back(v);
	grafo[v].push_back(u);
}

void dfs(int u)
{
	if(visitados[u]) return;
	visitados[u] = true;

for(auto v : grafo[u])
		dfs(v);
}

int solve()
{
	int r = 0;

	for(int i = 0; i < MAXN; i++)
		r += visitados[i];

	return r;
}



int main(int argc, char** argv)
{
	optimize;

	int N;

	while((cin >> N) && N)
	{
		reset();
		
		for(int i = 0; i < N; i++)
		{
			pii x = le();
			addAresta(x.first, x.second);
		}

		dfs(1);

		int r = solve();

		cout << r << endl;
	}


	return 0;
}
