#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

int pai[MAXN];
int peso[MAXN];

class Aresta{
private:
	int V1, V2, custo;
public:
	Aresta(int V1, int V2, int custo){
		this->V1 = V1;
		this->V2 = V2;
		this->custo = custo;
	}

	int Obter_V1(){
		return V1;
	}

	int Obter_V2(){
		return V2;
	}

	int Obter_Custo(){
		return custo;
	}

	bool operator < (const Aresta& a) const{
		return custo < a.custo;
	}
};

class Grafo{
private:
	int V;
	deque<Aresta> arestas;
public:
	Grafo(int V){
		this->V = V;
	}

	void addAresta(int v1, int v2, int custo){
		Aresta a(v1, v2, custo);
		arestas.push_back(a);
	}

	int find(int x){
		if(pai[x] == x)
			return x;
		return pai[x] = find(pai[x]);
	}

	void join(int x, int y){
		x = find(x);
		y = find(y);
		
		if(peso[x] < peso[y]){
			pai[x] = y;
			peso[y]++;
		}else{
			pai[y] = x;
			peso[x]++;
		}
	}

	int Kruskal(){
		int mst = 0;
		sort(arestas.begin(), arestas.end());

		for (int i = 0; i < V; ++i)
		{
			int v1 = arestas[i].Obter_V1();
			int v2 = arestas[i].Obter_V2();
			if(find(v1) != find(v2)){
				join(v1, v2);
				mst += arestas[i].Obter_Custo();
			}
		}

		return mst;
	}

};

int main(int argc, char const *argv[])
{
	int N, F, R, A, B, C;
	cin >> N >> F >> R;
	for (int i = 1; i <= N; ++i)
	{
			peso[i] = 0;
			pai[i] = i;
	}

	Grafo Ferrovias(F);
	Grafo Rodovias(R);
	for (int i = 0; i < F; Ferrovias.addAresta(A, B, C), ++i)
		cin >> A >> B >> C;

	for (int i = 0; i < R; Rodovias.addAresta(A, B, C), ++i)
		cin >> A >> B >> C;
	
	cout << Ferrovias.Kruskal() + Rodovias.Kruskal() << endl;
	return 0;
}