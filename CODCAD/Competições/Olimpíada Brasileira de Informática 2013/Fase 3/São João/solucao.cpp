#include <bits/stdc++.h>

using namespace std;

int ancestral = 0;

class Grafo{
private:
	int V;
	list<int> * vizinhos;
public:
	Grafo(int V){
		this->V = V;
		vizinhos = new list<int>[V];
	}

	void addAresta(int a, int b){
		vizinhos[a].push_back(b);
		vizinhos[b].push_back(a);
	}

	int DFS(int u, int dist[]){

		list<int>::iterator it = vizinhos[u].begin();

		for(; it != vizinhos[u].end(); it++){
			if(dist[*it] != -1) continue;

			dist[*it] = dist[u] + 1;

			if(dist[*it] > dist[ancestral])
				ancestral = *it;
			DFS(*it, dist);
		}

		return ancestral;
	}
};

int main(int argc, char const *argv[])
{
	int N, x, y;

	scanf("%d", &N);

	int distancias_A[N];
	int distancias_B[N];

	Grafo g(N);

	for (int i = 1; i < N; ++i)
		scanf("%d %d", &x, &y), g.addAresta(--x, --y);

	//Calcula qual é um dos vertices do diametro...
	memset(distancias_A, -1, sizeof(distancias_A));
	distancias_A[0] = ancestral = 0;
	int A = g.DFS(0, distancias_A);

	//Calcula a distancia entre o vertice 'A' do diametro
	//Para todos os outros vertices...
	//E pega qual o outro vertice do diametro...
	memset(distancias_A, -1, sizeof(distancias_A));
	distancias_A[A] = 0;
	ancestral = A;
	int B = g.DFS(A, distancias_A);

	//Calcula a distancia entre o vertice 'B' do diametro
	//Para todos os outros vertices...
	memset(distancias_B, -1, sizeof(distancias_B));
	distancias_B[B] = 0;
	ancestral = B;
	g.DFS(B, distancias_B);

	int Q, U, M;

	cin >> Q;

	for (int i = 0; i < Q; ++i)
	{
		scanf("%d %d", &U, &M);
		U--;

		//Conto quantos vértices eu posso visitar sem precisar voltar...
		//Limitado ou a quantidade de corredores que posso percorrer e
		//Ao tamanho do maior caminho até uma folha...

		int r = min(M, max(distancias_A[U], distancias_B[U])) + 1;

		//Caso sobre algum corredor que eu possa usar...
		//Vejo a quantidade de vértices que possi visitar...
		//Limitado a metade dos corredores livres, tendo em vista eu gasto 2
		//Corredores para visitar qualquer outro vertice, e...
		//A quantidade de vertices restantes a serem visitados...

		r += min((M - r + 1) / 2, N - r);

		printf("%d\n", r);
	}
	return 0;
}