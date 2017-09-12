#include <bits/stdc++.h>

using namespace std;

bool ok = true;

class Grafo{
private:
	int V;
	list<int> * visinhos;

public:
	Grafo(int V){
		this->V = V;
		visinhos = new list<int> [V];
	}

	void addAresta(int v1, int v2){
		visinhos[v2].push_back(v1);
	}

	int DFS(int u){
		int da_vez, filhos, total = 1;

		list<int>::iterator it;
		for(it = visinhos[u].begin(); it != visinhos[u].end(); it++){
			da_vez = DFS(*it);
			if(it == visinhos[u].begin())
				filhos = da_vez;
			else if(filhos != da_vez)
				ok = false;

			total += da_vez;
		}

		return total;
	}
};

int main(int argc, char const *argv[])
{
	int N, a, b;
	cin >> N;

	Grafo g(N + 1);

	for (int i = 0; i < N; g.addAresta(a, b), ++i)
		cin >> a >> b;

	g.DFS(0);

	cout << (ok ? "bem" : "mal") << endl;
	return 0;
}