#include <bits/stdc++.h>
#define INFINITO 10000000
#define pii pair<int, int>

using namespace std;

int N, M;

class Aresta{
private:
	int U, D, G, R;
public:
	Aresta(int U, int D, int G, int R){
		this->U = U;
		this->D = D;
		this->G = G;
		this->R = R;
	}

	int ObterU(){
		return U;
	}

	int ObterD(){
		return D;
	}

	int ObterG(){
		return G;
	}

	int ObterR(){
		return R;
	}
};

class Grafo{
private:
	int V;
	list<Aresta> * vizinhos;
public:
	Grafo(int V){
		this->V = V;
		vizinhos = new list<Aresta>[V];
	}

	void addAresta(int A, int B, int D, int G, int R){
		Aresta a(B, D, G, R);
		vizinhos[A].push_back(a);
	}

	int Dijkstra(){
		bool visitados[V];
		memset(visitados, false, sizeof(visitados));

		priority_queue<pii, vector<pii>, greater<pii> > pilha;
		pilha.push(pii(0, 0));

		while(!pilha.empty()){
			int d = pilha.top().first;
			int u = pilha.top().second;

			pilha.pop();

			if(u == N - 1) return d;

			if(visitados[u]) continue;
			visitados[u] = true;

			list<Aresta>::iterator it = vizinhos[u].begin();

			for(; it != vizinhos[u].end(); it++){
				int v = it->ObterU();
				int D = it->ObterD();
				int G = it->ObterG();
				int R = it->ObterR();

				int instante = d + D;

				if(instante % (G + R) >= G)
					instante += (G + R - (instante % (G + R)));

				pilha.push(pii(instante, v));
			}
		}
		return -1;
	}
};

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	int A, B, D, G, R;

	cin >> N >> M;

	Grafo g(N);

	for (int i = 0; i < M; g.addAresta(--A, --B, D, G, R), ++i)
		cin >> A >> B >> D >> G >> R;

	cout << g.Dijkstra() << endl;
	return 0;
}