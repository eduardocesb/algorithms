#include <bits/stdc++.h>
#define MAXS 260
#define INFINITO 9999999

using namespace std;

class Grafo{
private:
	int V;
	int distancia[MAXS][MAXS];
public:
	Grafo(int V){
		this->V = V;
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
				distancia[i][j] = INFINITO;
			distancia[i][i] = 0;
		}
	}

	void addAresta(int v1, int v2, int custo){
		distancia[v1][v2] = distancia[v2][v1] = custo;
	}

	void Floyd_Warshall(){
		int r = INFINITO, atual;
		for (int k = 0; k < V; ++k)
		{
			for (int i = 0; i < V; ++i)
			{
				atual = 0;
				for (int j = 0; j < V; ++j)
				{
					distancia[i][j] = distancia[j][i] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);
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
	int S, C, A, B, D;
	cin >> S >> C;

	Grafo g(S);

	for (int i = 0; i < C; g.addAresta(A - 1, B - 1, D), ++i)
		cin >> A >> B >> D;

	g.Floyd_Warshall();
	return 0;
}