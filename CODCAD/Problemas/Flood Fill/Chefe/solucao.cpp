#include <bits/stdc++.h>
#define MAXN 510
#define INFINITO 110

using namespace std;

class Grafo{
private:
	int V;
	bool visinhos[MAXN][MAXN];
	int idade[MAXN];

public:
	Grafo(int V){
		this->V = V;
		memset(visinhos, false, sizeof(visinhos));
	}

	void add_visinho(int v1, int v2){
		visinhos[v1][v2] = true;
	}

	void add_idade(int id, int valor){
		idade[id] = valor;
	}

	void swap_(int a, int b){
		swap(visinhos[a], visinhos[b]);

		for(int i = 1; i <= V; i++)
			swap(visinhos[i][a], visinhos[i][b]);
	}

	void Floyd_Warshall(){
		for(int k = 1; k <= V; k++)
			for(int i = 1; i <= V; i++)
				for(int j = 1; j <= V; j++)
					//Se exite caminha e 'i' para 'k' e de 'k' para 'j'
					//Significa que existe caminho de 'i' para 'j'
					if(visinhos[i][k] && visinhos[k][j])
						visinhos[i][j] = true;
	}

	int query(int u){
		int r = INFINITO;

		for(int i = 1; i <= V; i++)
			if(visinhos[i][u])
				r = min(r, idade[i]);

		return (r == INFINITO ? -1 : r);
	}
};

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	int N, M, Q;
	char op;

	while((cin >> N >> M >> Q)){
		Grafo g(N);

		for(int i = 1, x; i <= N; g.add_idade(i++, x))
			cin >> x;

		for(int i = 0, x, y; i < M; g.add_visinho(x, y), i++)
			cin >> x >> y;

		g.Floyd_Warshall();

		for(int i = 0, x, y; i < Q; i++){
			cin >> op >> x;

			if(op == 'P'){
				int idade = g.query(x);

				if(idade == -1)
					cout << '*' << endl;
				else
					cout << idade << endl;

			}else{
				cin >> y;
				g.swap_(x, y);
			}
		}
		
	}
	return 0;
}