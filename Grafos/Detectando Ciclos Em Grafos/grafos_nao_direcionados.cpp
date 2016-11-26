//Utilizando o UNION_FIND para detectar ciclos em grafos não direcionados...
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Aresta{
private:
	int v1, v2, custo;
public:
	Aresta(int v1, int v2, int custo){
		this->v1 = v1;
		this->v2 = v2;
		this->custo = custo;
	}
	
	int obterV1(){
		return v1;
	}
	int obterV2(){
		return v2;
	}
	int obterCusto(){
		return custo;
	}
	
	bool operator < (const Aresta& aresta2) const{
		return (custo < aresta2.custo);
	}
};


class Grafo{
private:
	int V;
	vector<Aresta> arestas;
public:
	Grafo(int V){
		this->V = V;
	}
	//Funções do meu grafo...
	int busca(int subset[], int v);
	void unir(int subset[], int v1, int v2);
	void addAresta(int v1, int v2, int custo);
	void kruskal();
};

int Grafo::busca(int subset[], int v){
	if(subset[v] == -1){
		return v;
	}else{
		return busca(subset, subset[v]);
	}
}

void Grafo::unir(int subset[], int v1, int v2){
	int v1_set = busca(subset, v1);
	int v2_set = busca(subset, v2);
	subset[v1_set] = v2_set;
}
void Grafo::addAresta(int v1, int v2, int custo){
	Aresta aresta(v1, v2, custo);
	arestas.push_back(aresta);
}
void Grafo::kruskal(){
	vector<Aresta> arvore;
	int size_arestas = arestas.size();
	
	sort(arestas.begin(), arestas.end());
	
	int * subset = new int[V];
	
	memset(subset, -1, sizeof(int) * V);
	for(int i = 0; i<size_arestas; i++){
		int v1 = busca(subset, arestas[i].obterV1());
		int v2 = busca(subset, arestas[i].obterV2());
		if(v1 != v2){
			arvore.push_back(arestas[i]);
			unir(subset, v1, v2);
		}
	}
	int size_arvore = arvore.size();
	for(int i=0;i<size_arvore; i++){
		char v1 = 'A' + arvore[i].obterV1();
		char v2 = 'A' + arvore[i].obterV2();
		cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterCusto() << 					endl;
	}
}



int main(){
	Grafo g(7);
	g.addAresta(0, 1, 7);
	g.addAresta(0, 3, 5);
	g.addAresta(1, 2, 8);
	g.addAresta(1, 3, 9);
	g.addAresta(1, 4, 7);
	g.addAresta(2, 4, 5);
	g.addAresta(3, 4, 15);
	g.addAresta(3, 5, 6);
	g.addAresta(4, 5, 8);
	g.addAresta(4, 6, 9);
	g.addAresta(5, 6, 11);
	
	g.kruskal();
	
	return 0;
}
