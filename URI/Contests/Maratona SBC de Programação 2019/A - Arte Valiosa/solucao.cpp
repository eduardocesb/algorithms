#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define MAXN 100100

using namespace std;

int M, N, K;

struct Ponto
{
	int x, y, raio;

	bool p1, p2, p3, p4;

	Ponto(int a, int b, int c)
	{
		x = a;
		y = b;
		raio = c;

		p1 = (y + raio >= N);
		p2 = (x + raio >= M);
		p3 = (y - raio <= 0);
		p4 = (x - raio <= 0);
	}

	inline int distancia(Ponto b)
	{
		return ((x - b.x) * (x - b.x)) + ((y - b.y) * (y - b.y));
	}

	inline bool conecta(Ponto b)
	{
		return distancia(b) <= ((raio + b.raio) * (raio + b.raio));
	}
};

vector<int> grafo[MAXN];
vector<Ponto> pontos;
bool visitados[MAXN];

void addAresta(int u, int v)
{
	grafo[u].push_back(v);
	grafo[v].push_back(u);
}

void precalc()
{
	for(int i = 0; i < K; i++)
		for(int j = i + 1; j < K; j++)
			if(pontos[i].conecta(pontos[j]))
				addAresta(i, j);
}

bool parede1, parede2, parede3, parede4;

void dfs(int u)
{
	if(visitados[u]) return;

	visitados[u] = true;

	parede1 += pontos[u].p1;
	parede2 += pontos[u].p2;
	parede3 += pontos[u].p3;
	parede4 += pontos[u].p4;

	for(auto v : grafo[u])
		dfs(v);
}

bool solve()
{
	for(int i = 0; i < K; i++)
	{
		parede1 = parede2 = parede3 = parede4 = false;
		dfs(i);

		if(parede1 && parede2) return false;
		if(parede1 && parede3) return false;
		if(parede2 && parede4) return false;
		if(parede3 && parede4) return false;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	optimize;

	scanf("%d %d %d", &M, &N, &K);

	int a, b, c;

	for(int i = 0; i < K; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		pontos.push_back(Ponto(a, b, c));
	}

	precalc();

	printf("%c\n", (solve() ? 'S' : 'N'));

	return 0;
}