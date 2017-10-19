#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int r = MAXN;

class Grafo{
private:
	int V;
	list<int> * vizinhos;
	int pai[MAXN];

public:
	Grafo(int V){
		this->V = V;
		vizinhos = new list<int>[V];

		memset(pai, -1, sizeof(pai));
	}

	void addAresta(int v1, int v2){
		vizinhos[v1].push_back(v2);
		vizinhos[v2].push_back(v1);
	}

	int dfs(int u){
		//Para pegar as duas menores distancias entre duas folhas...
		pair<int, int> menor(MAXN, MAXN);

		//Se for um nó folha informo que a primeira menor distancia é 0
		//Ou seja, é a distancia entre ele e ele mesmo...
		if(vizinhos[u].size() == 1)
			menor.first = 0;

		list<int>::iterator it = vizinhos[u].begin();

		for(; it != vizinhos[u].end(); it++){
			if(pai[u] == *it) continue;

			pai[*it] = u;

			//Vejo se a distância entre até o próximo nó folha
			//É melhor do que a que eu já tinha...
			menor.second = min(menor.second, dfs(*it));

			//Se a segunda menor distancia for menor que a primeira...
			//Inverto as duas...
			if(menor.first > menor.second)
				swap(menor.first, menor.second);
		}

		//Vejo se é melhor atualizar a distancia com as
		//Duas menores distancia até então...
		r = min(r, menor.first + menor.second);

		//Retorno a distancia do nó folha mais próximo dele...
		return menor.first + 1;
	}
};

int main(int argc, char const *argv[])
{
	int N, x, y;

	cin >> N;

	Grafo g(N);

	for (int i = 1; i < N; g.addAresta(--x, --y), ++i)
		cin >> x >> y;

	g.dfs(0);

	cout << r << endl;
	return 0;
}