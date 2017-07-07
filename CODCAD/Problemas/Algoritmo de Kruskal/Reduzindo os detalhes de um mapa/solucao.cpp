#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Aresta{
private:
	int vertice1, vertice2, custo;
public:
	Aresta(int v1, int v2, int custo){
		vertice1 = v1;
		vertice2 = v2;
		this->custo = custo;
	}

	int V1(){
		return vertice1;
	}

	int V2(){
		return vertice2;
	}

	int CUSTO(){
		return custo;
	}

	bool operator < (const Aresta& a) const{
		return custo < a.custo;
	}
};


class Grafo
{
private:
	int V;
	vector<Aresta> arestas;
public:
	Grafo(int V){
		this->V = V;
	}

	void addAresta(int v1, int v2, int custo){
		Aresta a(v1, v2, custo);
		arestas.push_back(a);
	}

	int buscar(int subset[], int i){
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	void unir(int v1, int v2, int subset[]){
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	int Kruskal(){
		int r = 0;
		int qtd_arestas = arestas.size();
		int * subset = new int[V];
		sort(arestas.begin(), arestas.end());
		memset(subset, -1, sizeof(int) * V);
		for (int i = 0; i < qtd_arestas; ++i)
		{
			int v1 = buscar(subset, arestas[i].V1());
			int v2 = buscar(subset, arestas[i].V2());
			if(v1 != v2){
				unir(v1, v2, subset);
				r += arestas[i].CUSTO();
			}
		}
		return r;
	}
};

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;

	Grafo mapa(N);

	for (int i = 0; i < M; ++i)
	{
		int v1, v2, custo;
		cin >> v1 >> v2 >> custo;
		mapa.addAresta(v1 - 1, v2 - 1, custo);
	}

	cout << mapa.Kruskal() << endl;
	return 0;
}