#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo{
private:
	int V;
	list<pair<int, int> > *caminhos;
public:
	Grafo(int V){
		this->V = V;
		caminhos = new list<pair<int,int> >[V];
	}

	void addAresta(int v1, int v2, int custo){
		caminhos[v1].push_back(make_pair(v2, custo));
		caminhos[v2].push_back(make_pair(v1, custo));
	}

	int Dijkstra(int origem, int destino){
		bool visitados[V];
		int distancia[V];
		for (int i = 0; i < V; ++i)
		{
			visitados[i] = false;
			distancia[i] = INFINITO; 
		}
		distancia[0] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

		pq.push(make_pair(0, 0));
		while(!pq.empty()){
			pair<int, int> no = pq.top();
			pq.pop();
			int u = no.second;
			if(!visitados[u]){
				visitados[u] = true;
				list<pair<int, int> >::iterator it;
				for (it = caminhos[u].begin(); it != caminhos[u].end(); it++)
				{
					int valor = it->second;
					int vertice = it->first;
					if(distancia[vertice] > (distancia[u] + valor)){
						distancia[vertice] = distancia[u] + valor;
						pq.push(make_pair(distancia[vertice], vertice));
					}
				}
			}
		}
		return distancia[destino];
	}
};

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	Grafo mapa(N+2);
	for (int i = 0; i < M; ++i)
	{
		int v1, v2, custo;
		cin >> v1 >> v2 >> custo;
		mapa.addAresta(v1, v2, custo);
	}

	int r = mapa.Dijkstra(0, N+1);
	cout << r << endl;
	return 0;
}