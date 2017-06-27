#include <iostream>
#include <list>
#include <stack>
#include <string.h>

using namespace std;

class Grafo{
private:
	int V;
	list<int> *visinhos;

	void preenche(int v, bool visitados[], stack<int>& pilha){
		visitados[v] = true;

		list<int>::iterator it;
		for(it = visinhos[v].begin(); it != visinhos[v].end(); it++){
			if(!visitados[*it]){
				preenche(*it, visitados, pilha);
			}
		}

		pilha.push(v);
	}

	void DFS(int v, bool visitados[]){
		visitados[v] = true;
		//cout << v << " ";
		list<int>::iterator it;
		for(it = visinhos[v].begin(); it != visinhos[v].end(); it++){
			if(!visitados[*it]){
				DFS(*it, visitados);
			}
		}
	}
public:
	Grafo(int V){
		this->V = V;
		visinhos = new list<int>[V];
	}

	void addAresta(int v1, int v2){
		visinhos[v1].push_back(v2);
		visinhos[v2].push_back(v1);
	}

	Grafo ObterGrafoTransposto(){
		Grafo gt(V);
		for(int i = 0; i < V; i++){
			list<int>::iterator it;
			for(it = visinhos[i].begin(); it != visinhos[i].end(); it++){
				gt.visinhos[*it].push_back(i);
			}
		}
		return gt;
	}

	int componentes(){
		stack<int> pilha;
		bool * visitados = new bool[V];
		memset(visitados, false, sizeof(bool) * V);

		for(int i = 0; i < V; i++){
			if(!visitados[i]){
				preenche(i, visitados, pilha);
			}
		}
		memset(visitados, false, sizeof(bool) * V);

		Grafo gt = ObterGrafoTransposto();
		int n = 0;
		while(!pilha.empty()){
			int v = pilha.top();
			pilha.pop();
			if(!visitados[v]){
				gt.DFS(v, visitados);
				n++;
				//cout << endl;
			}
		}
		return n;
	}
};


int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	Grafo g(N+1);
	for (int i = 0; i < M; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		g.addAresta(v1, v2);
	}

	int componentes = g.componentes();
	cout << componentes - 1 << endl;
	return 0;
}