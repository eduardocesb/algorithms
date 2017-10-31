#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

class Grafo{
private:
	int V;
	list<int> * vizinhos;

	int cor[MAXN];
public:
	Grafo(int V){
		this->V = V;
		vizinhos = new list<int>[V];

		memset(cor, -1, sizeof(cor));
	}

	void addAresta(int u, int v){
		vizinhos[u].push_back(v);
		vizinhos[v].push_back(u);
	}

	bool DFS(int u){
		bool ok = true;

		for(auto v : vizinhos[u]){
			if(cor[v] == cor[u])
				return false;
			else if(cor[v] == -1){
				cor[v] = !cor[u];
				ok = DFS(v);
			}
		}

		return ok;
	}

	bool solve(){

		bool ok = true;

		for (int i = 0; ok && i < V; ++i)
			if(cor[i] == -1){
				cor[i] = 1;
				ok = DFS(i);
			}

		return ok;
	}
};

int main(int argc, char const *argv[])
{
	int N;

	while(scanf("%d", &N) && N){
		//Crio meu grafo...
		Grafo g(N);

		int u;
		for (int j = 0; j < N; ++j)
		{
			scanf("%d ", &u);

			u--;

			//Lê a lista de vizinhos de 'u'...
			char c;
			string v = "";

			while(scanf("%c", &c) && c != '\n' && c != '\0')
				if(c == ' ')
					//Adiciona a aresta (u, v)...
					g.addAresta(u, stoi(v) - 1), v = "";
				else
					v += c;

			//Adiciona a aresta (u, v)...
			g.addAresta(u, stoi(v) - 1);
		}

		//Caso possa dividir o grafo em dois...
		if(g.solve())
			printf("SIM\n");
		else
			printf("NAO\n");
	}
	return 0;
}