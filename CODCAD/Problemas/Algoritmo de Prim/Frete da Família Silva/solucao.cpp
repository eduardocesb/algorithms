#include <bits/stdc++.h>
#define INFINITO 999999999
#define MAXN 1010
#define pii pair<int, int>
#define PB push_back
#define MP make_pair

using namespace std;

class Grafo{
private:
	int V;
	list<pii> * visinhos;
public:
	Grafo(int V){
		this->V = V;
		visinhos = new list<pii> [V];
	}

	void addAresta(int v1, int v2, int custo){
		visinhos[v1].PB(MP(v2, custo));
		visinhos[v2].PB(MP(v1, custo));
	}

	int Prim(){
		int distancia[V];
		bool visitados[V];

		//Inicializo todos como não visitados...
		memset(visitados, false, sizeof(visitados));

		//Informo que, inicialmente, todas as distâncias são infinitas...
		for (int i = 1; i < V; ++i) distancia[i] = INFINITO;

		//A distância do vertice 0 é zero...
		distancia[0] = 0;

		priority_queue<pii, vector<pii>, greater<pii> > pq;

		pq.push(MP(0, 0));

		while(!pq.empty()){
			//Pego o vertice do topo e removo da fila...
			int v = pq.top().second;
			pq.pop();

			//Caso ele já tenha sido visitado...
			//Vai para o proximo loop...
			if(visitados[v]) continue;

			visitados[v] = true;

			list<pii>::iterator it;
			for (it = visinhos[v].begin(); it != visinhos[v].end(); it++)
			{
				int u = it->first;
				int distancia_atual = it->second;
				if(!visitados[u] && distancia[u] > distancia_atual){
					distancia[u] = distancia_atual;
					pq.push(MP(distancia_atual, u));
				}
			}
		}

		int distancia_total = 0;
		for (int atual = 0; atual < V; ++atual)
			distancia_total += distancia[atual];

		return distancia_total;
	}
};



int main(int argc, char const *argv[])
{
	int N, M, P, Q, U;
	cin >> N >> M;
	Grafo g(N);
	for (int i = 0; i < M; ++i)
	{
		cin >> P >> Q >> U;
		g.addAresta(P, Q, U);
	}

	cout << g.Prim() << endl;
	return 0;
}