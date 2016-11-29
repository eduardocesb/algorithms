/*
	Algoritmo de Kruskal...	
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Aresta{
	int vertice1, vertice2, peso;
public:
	Aresta(int v1, int v2, int peso){
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1(){
		return vertice1;
	}

	int obterVertice2(){
		return vertice2;
	}

	int obterPeso(){
		return peso;
	}

	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}

};

class Grafo{
	int V;
	vector<Aresta> arestas;
public:
	Grafo(int V){
		this->V= V;
	}

	void adicionarAresta(int v1, int v2, int peso){
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}