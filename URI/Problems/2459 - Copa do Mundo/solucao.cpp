#include <iostream>
#include <vector>
#include <algorithm>
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

	int ObterV1(){
		return vertice1;
	}

	int ObterV2(){
		return vertice2;
	}

	int ObterCusto(){
		return custo;
	}

	bool operator < (const Aresta& aresta2) const{
		return custo < aresta2.custo;
	}
};

int subset[102];
int r = 0;

class Grafo{
private:
	int V;
	vector<Aresta> arestas;
public:
	Grafo(int V){
		this->V = V;
	}

	void addAresta(int v1, int v2, int custo){
		Aresta aresta(v1, v2, custo);
		arestas.push_back(aresta);
	}

	int buscar(int subset[], int i){
		if(subset[i] == -1){
			return i;
		}
		return buscar(subset, subset[i]);
	}

	void unir(int subset[], int v1, int v2){
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	void kruskal(){
		sort(arestas.begin(), arestas.end());
		int size_arestas = arestas.size();
		for (int i = 0; i < size_arestas; ++i)
		{
			int v1 = buscar(subset, arestas[i].ObterV1());
			int v2 = buscar(subset, arestas[i].ObterV2());

			if(v1 != v2){
				unir(subset, v1, v2);
				r += arestas[i].ObterCusto();
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	int N, F, R;
	cin >> N >> F >> R;
	memset(subset, -1, sizeof(int) * N);

	Grafo Ferrovias(N+1);
	Grafo Rodovias(N+1);

	int v1, v2, custo;

	for (int i = 0; i < F; ++i)
	{
		cin >> v1 >> v2 >> custo;
		Ferrovias.addAresta(v1, v2, custo);
	}
	Ferrovias.kruskal();

	for (int i = 0; i < R; ++i)
	{
		cin >> v1 >> v2 >> custo;
		Rodovias.addAresta(v1, v2, custo);
	}
	Rodovias.kruskal();

	cout << r << endl;
	return 0;
}