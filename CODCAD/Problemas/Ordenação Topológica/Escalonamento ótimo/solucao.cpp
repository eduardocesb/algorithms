#include <bits/stdc++.h>
#define MAXN 50010

using namespace std;

class Grafo{
private:
	int V;
	list<int> * visinhos;
	int grau[MAXN];

public:
	Grafo(int V){
		this->V = V;
		visinhos = new list<int> [V];
		for (int i = 0; i < V; ++i)
			grau[i] = 0;
	}

	void addAresta(int v1, int v2){
		visinhos[v1].push_back(v2);
		grau[v2]++;
	}

	void Ordernacao_Topologica(){
		set<int> pq;
		int resp[V], cont = 0;

		for (int i = 0; i < V; ++i)
			if(!grau[i])
				pq.insert(i);

		while(!pq.empty()){
			int v = *pq.begin();
			pq.erase(pq.begin());

			resp[cont++] = v;
			
			list<int>::iterator it;
			for(it = visinhos[v].begin(); it != visinhos[v].end(); it++)
				if(--grau[*it] == 0)
					pq.insert(*it);
		}

		if(cont != V){
			cout << '*' << endl;
			return;
		}

		for (int i = 0; i < V; ++i)
			cout << resp[i] << endl;
	}
};


int main(int argc, char const *argv[])
{
	int N, M, A, B;
	cin >> N >> M;
	Grafo g(N);

	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B;
		g.addAresta(A, B);
	}

	g.Ordernacao_Topologica();

	return 0;
}