#include <bits/stdc++.h>
#define MAXN 110
#define INFINITO 9999999

using namespace std;

class Grafo{
private:
	int V;
	int distancia[MAXN][MAXN];
public:
	Grafo(int V){
		this->V = V;
		for (int i = 0; i < V; ++i){
			for (int j = 0; j < V; ++j)
				distancia[i][j] = INFINITO;
			distancia[i][i] = 0;
		}
	}

	void addAresta(int v1, int v2, int custo){
		distancia[v1][v2] = distancia[v2][v1] = custo;
	}

	void Floyd_Warshall(){
		int r = INFINITO, atual = 0;
		for (int k = 0; k < V; ++k){
			for (int i = 0; i < V; ++i){
				atual = 0;
				for (int j = 0; j < V; ++j){
					distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);
					atual = max(atual, distancia[i][j]);
				}
				r = min(r, atual);
			}
		}

		cout << r << endl;
	}
};

int main(int argc, char const *argv[])
{
	int N, M, U, V, W;
	cin >> N >> M;
	Grafo g(N);

	for (int i = 0; i < M; g.addAresta(U, V, W), ++i)
		cin >> U >> V >> W;

	g.Floyd_Warshall();

	return 0;
}