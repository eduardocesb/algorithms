#include <bits/stdc++.h>
#define INFINITO 1000000000
#define MAXN 1010

using namespace std;

struct edge
{
	int to, F, C;
	edge(int u = 0, int f = 0, int c = 0)
	{
		to = u, F = f, C = c;
	}

} Aresta[MAXN];

vector<int> vizinhos[MAXN];
int visitados[MAXN];
int cur, S, T = 25, tempo = 1;

void add_aresta(int a, int b, int cp, int rc)
{
	Aresta[cur] = edge(b, 0, cp);
	vizinhos[a].push_back(cur++);
	Aresta[cur] = edge(a, 0, rc);
	vizinhos[b].push_back(cur++);
}

int dfs(int S, int F)
{
	if(S == T) return F;
	visitados[S] = tempo;

for(int u : vizinhos[S])
		if(visitados[Aresta[u].to] < tempo && Aresta[u].C - Aresta[u].F > 0)
			if(int a = dfs(Aresta[u].to, min(F, Aresta[u].C - Aresta[u].F)))
			{
				Aresta[u].F += a;
				Aresta[u ^ 1].F -= a;
				return a;
			}
	return 0;

}

int Flow()
{
	int r = 0;
	while(int a = dfs(S, INFINITO))
		r += a, tempo++;
	return r;
}

int main(int argc, char** argv)
{
	int N, C;

	char A, B;

	cin >> N;

	while(N--)
	{
		cin >> A >> B >> C;
		add_aresta(A - 'A', B - 'A', C, C);
	}
	
	cout << Flow() << endl;

	return 0;
}
