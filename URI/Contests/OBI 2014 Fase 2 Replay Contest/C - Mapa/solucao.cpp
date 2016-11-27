#include <iostream>
#include <list>

using namespace std;

int r = 0;
int N;

list<pair<int, int> > *adj;

class Grafo{
private:
	int V;
public:
	Grafo(int V){
		this->V = V;
		adj = new list<pair<int, int> > [V];
	}

	void addAresta(int v1, int v2, int custo){
		adj[v1].push_back(make_pair(v2, custo));
		adj[v2].push_back(make_pair(v1, custo));
	}	

};

void dfs(int v, bool visitados[], bool situacao){
	if(!visitados[v]){
		visitados[v] = true;
		list<pair<int, int> >:: iterator it;
		bool achou = false;
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(it->second == 1 && !visitados[it->first]){
				achou = true;
				r++;
			}else if(situacao && !visitados[it->first]){
				achou = true;
				r++;
			}
			dfs(it->first, visitados, achou);

		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> N;
	Grafo mapa(N+1);
	bool visitados[N+1];
	for (int i = 1; i < N; ++i)
	{
		int v1, v2, custo;
		cin >> v1 >> v2 >> custo;
		mapa.addAresta(v1, v2, custo);
	}

	for(int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			visitados[j] = false;
		}
		dfs(i, visitados, false);
	}

	cout << (r/2) << endl;
	return 0;
}