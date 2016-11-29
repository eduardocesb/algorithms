#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; // número de vértices

	// ponteiro para um array contendo as listas de adjacências
	list<pair<int, int> > * adj;

public:

	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o número de vértices

		/*
			cria as listas onde cada lista é uma lista de pairs
			onde cada pair é formado pelo vértice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 à v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de distâncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		return dist[dest];
	}

	bool tem_ligacao(int orig, int dest){
		list<pair<int, int> >::iterator it;
		for(it = adj[orig].begin(); it != adj[orig].end(); it++){
			int vertice = it->first;
			if(vertice == dest){
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	int N, E;
	cin >> N >> E;
	while(N != 0 || E != 0){
		Grafo g(N+1);
		for (int i = 0; i < E; ++i)
		{
			int v1, v2, custo;
			cin >> v1 >> v2 >> custo;
			g.addAresta(v1, v2, custo);
		}
		int O;
		cin >> O;
		for (int i = 0; i < O; ++i)
		{
			int orig, dest;
			cin >> orig >> dest;
			if(g.tem_ligacao(orig, dest)){
				cout << 0 << endl;
			}else{
				int n = g.dijkstra(orig, dest);
				if(n == INFINITO){
					cout << "Nao e possivel entregar a carta" << endl;
				}else{
					cout << n << endl;
				}
			}

		}
		cin >> N >> E;
	}

	return 0;
}