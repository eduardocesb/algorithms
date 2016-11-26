#include <iostream>
#include <queue>
#include <list>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V;
	list<pair<int, int> > *adj;
public:
	Grafo(int V){
		this->V = V;
		adj = new list<pair<int, int> > [V];
	}
	
	void addAresta(int v1, int v2, int custo){
		adj[v1].push_back(make_pair(v2, custo));
	}
	
	int dijkstra(int org, int dest){
		int dist[V];
		bool visitados[V];
		
		priority_queue<pair<int, int>, vector<pair<int, int> >,  							greater<pair<int, int> > > pq;
		for(int i=0; i<=V; i++){
			dist[i] = INFINITO;
			visitados[i] = false;
		}
		pq.push(make_pair(dist[org], org));
		dist[org] = 0;
		while(!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			int u = p.second;
			if(visitados[u] == false){
				visitados[u] = true;
				list<pair<int, int> >:: iterator it;
				for(it = adj[u].begin(); it != adj[u].end(); it++){
					int v = it->first;
					int custo = it->second;
					if(dist[v] > (custo + dist[u])){
						dist[v] = custo + dist[u];
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}
		return dist[dest];
	}
};

Grafo* newGrafo(int n){
	Grafo* x = new Grafo(n);
	return x;
}

int main(){

	int n,m;
	cin >> n >> m;
	while(n != 0 || m != 0){
		Grafo* g = newGrafo(n+1);		
		for(int i = 0; i<m; i++){
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
