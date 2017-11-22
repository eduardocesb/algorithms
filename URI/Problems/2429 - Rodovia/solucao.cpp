#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;

vector<int> vizinhos[MAXN];
bool visitados[MAXN];
bool flag;

int DFS(int u = 0)
{
	visitados[u] = true;
	
	int r = 1;

	for(auto v : vizinhos[u])
		if(!v)
			flag = true;
		else if(!visitados[v])
			r += DFS(v);

	return r;
}

int main(int argc, char const *argv[])
{
	int N;

	scanf("%d", &N);

	for (int i = 0, u, v; i < N; ++i)
	{
		scanf("%d %d", &u, &v);

		vizinhos[u - 1].push_back(v - 1);
	}

	int r = DFS();

	if(flag && r == N)
		puts("S");
	else
		puts("N");

	return 0;
}