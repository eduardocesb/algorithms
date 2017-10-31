#include <bits/stdc++.h>
#define MAXN 1010

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
	}

	bool DFS(int u){

		for(auto v : vizinhos[u])
			if(cor[v] == -1){
				cor[v] = !cor[u];

				if(!DFS(v)) return false;
			}else if(cor[v] == cor[u])
				return false;

		return true;
	}

	bool solve(){
		for (int i = 0; i < V; ++i)
			if(cor[i] == -1 && (cor[i] = 1))
				if(!DFS(i)) return false;

		return true;
	}
};

int main(int argc, char const *argv[])
{
	int N, x;

	scanf("%d", &N);

	Grafo g(N);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			//Caso eu não possa colocar as duas no mesmo tanque...
			if(scanf("%d", &x) && !x) g.addAresta(i, j);

	if(g.solve())
		printf("Bazinga!\n");
	else
		printf("Fail!\n");
	return 0;
}