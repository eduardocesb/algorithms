#include <bits/stdc++.h>
#define MAXN 1001000

using namespace std;

bool visitados[MAXN];
vector<int> vizinhos[MAXN];

void addAresta(int u, int v)
{
	vizinhos[u].push_back(v);
	vizinhos[v].push_back(u);
}

void DFS(int u)
{
	visitados[u] = true;

	for(auto v : vizinhos[u])
		if(!visitados[v])
			DFS(v);
}

int main(int argc, char const *argv[])
{
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0, u, v; i < M; ++i)
		scanf("%d %d", &u, &v), addAresta(u - 1, v - 1);

	int r = 0;

	for (int i = 0; i < N; ++i)
		if(!visitados[i])
			r++, DFS(i);


	printf("%d\n", r);

	return 0;
}