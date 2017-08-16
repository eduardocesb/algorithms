#include <bits/stdc++.h>
#define MAXN 260
#define INFINITO 9999999

using namespace std;

int distancia[MAXN];
int rota[MAXN];

class Grafo{
private:
	int V, C, K;
	list<pair<int, int> > * visinhos;
public:
	Grafo(int V, int C){
		this->V = V;
		this->C = C;
		for (int i = 0; i < V; ++i){
			rota[i] = 0;
			distancia[i] = INFINITO;
		}

		visinhos = new list<pair<int, int> > [V];
	}

	void addAresta(int v1, int v2, int custo){

		visinhos[v1].push_back(make_pair(v2, custo));
		visinhos[v2].push_back(make_pair(v1, custo));

		if(min(v1, v2) + 1 == max(v1, v2) && max(v1, v2) < C)
			for (int i = 0; i < max(v1, v2); ++i)
				rota[i] += custo;
		
	}

	int Dijkstra(int Origem, int Destino){

		bool visitados[V];
		memset(visitados, false, sizeof(visitados));

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		distancia[Origem] = 0;

		pq.push(make_pair(distancia[Origem], Origem));

		while(!pq.empty()){
			int u = pq.top().second;
			pq.pop();

			if(visitados[u]) continue;

			if(u < Destino){
				visitados[u] = true;
				distancia[Destino] = min(distancia[Destino], distancia[u] + rota[u]);
				continue;
			}

			list<pair<int, int> >::iterator it = visinhos[u].begin();

			for(; it != visinhos[u].end(); it++){
				int v = it->first;
				int c = it->second;

				if(distancia[v] > distancia[u] + c){
					distancia[v] = distancia[u] + c;
					pq.push(make_pair(distancia[v], v));
				}
			}
		}

		return distancia[Destino];
	}
};

int main(int argc, char const *argv[])
{
	int N, M, C, K, U, V, P;
	while((cin >> N >> M >> C >> K) && (N != 0 || M != 0 || C != 0 || K != 0)){
		Grafo g(N, C);

		for (int i = 0; i < M; g.addAresta(U, V, P), ++i)
			cin >> U >> V >> P;

		cout << g.Dijkstra(K, C - 1) << endl;
	}
	return 0;
}