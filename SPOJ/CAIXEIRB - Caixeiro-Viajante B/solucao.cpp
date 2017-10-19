#include <bits/stdc++.h>
#define MAXN 310

using namespace std;

class Grafo{
private:
	int V;
	list<int> * vizinhos;
	bool cidades[MAXN];
	int pai[MAXN];
public:
	Grafo(int V){
		this->V = V;
		vizinhos = new list<int> [V];

		memset(pai, -1, sizeof(pai));
		memset(cidades, false, sizeof(cidades));
	}

	void addAresta(int v1, int v2){
		vizinhos[v1].push_back(v2);
		vizinhos[v2].push_back(v1);
	}

	void visita_cidade(int x){
		cidades[x] = true;
	}

	int dfs(int u = 0){
		int r = 0;

		list<int>::iterator it = vizinhos[u].begin();

		for(; it != vizinhos[u].end(); it++){
			if(pai[u] == *it) continue;

			pai[*it] = u;

			r += dfs(*it);
		}

		if(r) return r + 2;
		if(cidades[u]) return 2;
		return 0;
	}
};

int main(int argc, char const *argv[])
{
	int N, M, x, y, t = 1;

	while((cin >> N >> M) && (N || M)){

		Grafo g(N);

		for (int i = 1; i < N; g.addAresta(--x, --y), ++i)
			cin >> x >> y;

		for (int i = 0; i < M; g.visita_cidade(--x), ++i)
			cin >> x;

		cout << "Teste " << t++ << endl;
		cout << g.dfs() - 2 << endl << endl;
	}
	return 0;
}