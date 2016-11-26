//Detectando Ciclos Em Grafos Direcionados...
#include <iostream>
#include <list>
#include <stack> //Pilha para usar na DFS...

using namespace std;

class Grafo{
private:
	int V;
	list<int> *visinhos;
	
public:
	Grafo(int V);
	void addAresta(int v1, int v2);
	
	//Faz uma DFS a partir de um determindado vertice...
	bool dfs(int v);
	
	bool temCiclo();

};

Grafo::Grafo(int V){
	this->V = V;
	visinhos = new list<int> [V];
}
void Grafo::addAresta(int v1, int v2){
	visinhos[v1].push_back(v2);
	//visinhos[v2].push_back(v1);
}
bool Grafo::dfs(int v){
	stack<int> pilha;
	bool visitados[V], pilha_rec[V];
	
	for(int i=0; i<V; i++){
		visitados[i] = false;
		pilha_rec[i] = false;
	}
	
	while(true){
		bool achou_vizinho = false;
		list<int>::iterator it;
		if(!visitados[v]){
			pilha.push(v);
			visitados[v] = true;
			pilha_rec[v] = true;
		}
		for(it = visinhos[v].begin(); it != visinhos[v].end(); it++){
			if(pilha_rec[*it]){
				return true;
			}else if(!visitados[*it]){
				achou_vizinho = true;
				break;
			}
		}
		if(!achou_vizinho){
			pilha_rec[pilha.top()] = false;
			pilha.pop();
			if(pilha.empty()){
				break;
			}
			v = pilha.top();
		}else{
			v = *it; 
		}
	}
	return false;
}

bool Grafo::temCiclo(){
	for(int i=0; i<V; i++){
		if(dfs(i)){
			return true;
		}
	}
	return false;
}

int main(){
	Grafo grafo(4);
	grafo.addAresta(0, 1);
	grafo.addAresta(0, 2);
	grafo.addAresta(1, 3);
	grafo.addAresta(3, 0);
	
	if(grafo.temCiclo()){
		cout << "Contem Ciclo!" << endl; 
	}else{
		cout << "Não Contem Ciclo!" << endl;
	}
	return 0;
}
