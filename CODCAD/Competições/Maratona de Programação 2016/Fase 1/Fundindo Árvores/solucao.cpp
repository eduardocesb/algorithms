#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 10100

using namespace std;

int melhor_canhota = 0, melhor_destra = 0;

class Vertice{
private:
	int filho_esquerdo;
	int filho_central;
	int filho_direito;
public:
	Vertice(int e = 0, int c = 0, int d = 0){
		filho_esquerdo = e;
		filho_central = c;
		filho_direito = d;
	}

	int get_fe(){
		return filho_esquerdo;
	}

	int get_fc(){
		return filho_central;
	}

	int get_fd(){
		return filho_direito;
	}
};

class Grafo{
private:
	int V;
	Vertice filhos[MAXN];
public:
	Grafo(int V){
		this->V = V;
		memset(filhos, 0, sizeof(filhos));
	}

	void addAresta(int i, int e, int c, int d){
		Vertice a(e, c, d);
		filhos[i] = a;
	}

	//Maior caminho que começa em qualquer vertice...
	int dfs(int u = 1, int melhor = 1){
		int e = 0, c = 0, d = 0;

		if(filhos[u].get_fe())
			e = dfs(filhos[u].get_fe(), 1);

		if(filhos[u].get_fc())
			c = dfs(filhos[u].get_fc(), melhor + 1);

		if(filhos[u].get_fd())
			d = dfs(filhos[u].get_fd(), 1);

		int r = max(max(melhor, c), max(e, d));

		return r;
	}

	//Maior caminho que começa na raiz...
	int dfs_2(int u = 1){
		if(filhos[u].get_fc())
			return 1 + dfs_2(filhos[u].get_fc());

		return 0;
	}
};

int main(int argc, char const *argv[])
{
	optimize;

	int N, M, id, e, c, d;

	cin >> N;

	Grafo canhota(N + 1);

	for (int i = 0; i < N; ++i)
	{
		cin >> id >> e >> c;

		canhota.addAresta(id, e, c, 0);
	}

	cin >> M;

	Grafo destra(M + 1);

	for (int i = 0; i < M; ++i)
	{
		cin >> id >> c >> d;

		destra.addAresta(id, 0, c, d);
	}

	//Tamanho do maior caminho que começa na raiz...
	int d1 = 1 + destra.dfs_2();
	int e1 = 1 + canhota.dfs_2();

	//Tamanho do maior caminho que começa em qualquer vertice...
	d = destra.dfs();
	e = canhota.dfs();

	//min(e1, d) é o que consigo economizar caso a raiz seja a destra...
	//min(d1, e) é o que consigo economizar caso a raiz seja a canhota...
	//O máximo que consigo enconomizar é o melhor entre o raiz ser a canhota e a raiz ser a destra...
	int vert_sup = max(min(e1, d), min(d1, e));

	//Respota final é a soma de todos os vértices (N + M) menos o que consigo enconomizar (vert_sup)...
	cout << (N + M - vert_sup) << endl;

	return 0;
}