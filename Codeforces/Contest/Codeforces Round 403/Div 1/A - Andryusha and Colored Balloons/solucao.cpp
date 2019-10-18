#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define MAXN 200020

using namespace std;

vector<int> grafo[MAXN];

void addAresta(int u, int v)
{
	grafo[u].push_back(v);
	grafo[v].push_back(u);
}

int cor[MAXN], K;

void dfs(int u, pii NAO_PODE)
{
	int i = 1;

	for(auto v : grafo[u])
	{
		if(cor[v] != -1) continue;

		if(i == NAO_PODE.first || i == NAO_PODE.second) i++;
		if(i == NAO_PODE.first || i == NAO_PODE.second) i++;

		cor[v] = i;

		K = max(K, cor[v]);

		dfs(v, pii(NAO_PODE.second, i));

		i++;
	}
}

void bfs()
{
	queue<pair<int, pii> > fila;

	fila.push(make_pair(1, pii(-1, 1)));
	cor[1] = 1;

	while(!fila.empty())
	{
		int u = fila.front().first;
		pii NAO_PODE = fila.front().second;

		fila.pop();

		int c = 1;

		for(int v : grafo[u])
		{
			if(cor[v] != -1) continue;

			if(c == NAO_PODE.first || c == NAO_PODE.second) c++;
			if(c == NAO_PODE.first || c == NAO_PODE.second) c++;

			cor[v] = c;

			K = max(K, c);

			fila.push(make_pair(v, pii(NAO_PODE.second, c)));

			c++;
		}
	}
}


int main(int argc, char const *argv[])
{
	memset(cor, -1, sizeof cor);

	int N, u, v;

	cin >> N;

	for(int i = 1; i < N; i++)
	{
		cin >> u >> v;

		addAresta(u, v);
	}

	// cor[1] = 1;

	// dfs(1, pii(-1, 1));

	bfs();

	cout << K << endl;

	for(int i = 1; i <= N; i++)
		cout << cor[i] << " "; 

	cout << endl;

	return 0;
}