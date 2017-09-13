#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> nivel;
unordered_map<int, int> total;


class Grafo{
private:
	int V;
	list<int> * visinhos;
public:
	Grafo(int V){
		this->V = V;
		visinhos = new list<int>[V];
	}

	void addAresta(int v1, int v2){
		visinhos[v1].push_back(v2);
	}

	void DFS(int u, int level){
		nivel[u] = level;
		total[level]++;

		list<int>::iterator it;

		for(it = visinhos[u].begin(); it != visinhos[u].end(); it++)
			DFS(*it, level + 1);
		
	}
};

int main(int argc, char const *argv[])
{
	int N, M, x;

	//Precisão de duas casas decimais...
	cout << fixed << setprecision(2);

	cin >> N >> M;

	Grafo g(N + 1);
	int quantidade[N];

	for (int i = 1; i <= N; quantidade[i] = 0, g.addAresta(x, i), ++i)
		cin >> x;


	g.DFS(0, 0);

	for (int i = 0; i < M; quantidade[nivel[x]]++, ++i)
		cin >> x;

	for (int i = 1; i <= N; ++i)
		if(total[i])
			cout << ((quantidade[i] * 100.0) / total[i]) << " ";

	return 0;
}