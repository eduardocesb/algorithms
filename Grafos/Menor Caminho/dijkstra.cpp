#include <iostream>
#include <queue>
#include <list>
#define INFINITO 10000000

using namespace std;

class Grafo{

private:
	int V;
	list<pair<int, int> > *visinhos;
public:
	Grafo(int V){
		this->V = V;
		visinhos = new list<pair<int, int> >[V];
	}
	
	void addAresta(int v1, int v2, int custo){
		visinhos[v1].push_back(make_pair(v2, custo));
	}
	
	int dijkstra(int org, int dest){
		priority_queue<pair<int, int>, vector<pair<int, int> >, 									greater<pair<int, int> > > pq;
		bool visitados[V+1];
		int distancia[V+1];
		for(int i=0; i<=V; i++){
			visitados[i] = false;
			distancia[i] = INFINITO;
		}
		distancia[org] = 0;
		pq.push(make_pair(distancia[org], org));
		
		while(!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			int u = p.second;
			if(!visitados[u]){
				visitados[u] = true;
				list<pair<int, int> >::iterator it;
				for(it = visinhos[u].begin(); it != visinhos[u].end(); it++){
					int v = it->first;
					int custo = it->second;
					if(distancia[v] > (distancia[u] + custo)){
						distancia[v] = distancia[u] + custo;
						pq.push(make_pair(distancia[v], v));
					}
				}
			}
		}
		return distancia[dest];
	}

};

Grafo* newGrafo(int n){
	Grafo* x = new Grafo(n);
	return x;
	
}

int main(){
	int n, m;
	cin >> n >> m;
	while(n != 0 || m != 0){
		Grafo* g = newGrafo(n+1);
		for(int i=0;i<m;i++){
			int v1, v2, custo;
			cin >> v1 >> v2 >> custo;
			g->addAresta(v1, v2, custo);
		}
		int org, dest;
		cin >> org >> dest;
		int r = g->dijkstra(org, dest);
		if(r == INFINITO){
			cout << -1 << endl;
		}else{
			cout << r << endl;
		}
		cin >> n >> m;
	}
	return 0;
}
