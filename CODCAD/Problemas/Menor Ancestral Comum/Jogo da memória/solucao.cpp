#include <bits/stdc++.h>
#define MAXN 50010
#define MAXL 20

using namespace std;

vector<vector<int> > par;

int pai[MAXN];
int nivel[MAXN];
int ancestral[MAXN][MAXL];

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
		visinhos[v2].push_back(v1);
	}

	void dfs(int u){
		list<int>::iterator it;
		for(it = visinhos[u].begin(); it != visinhos[u].end(); it++){
			int v = *it;

			if(nivel[v] == -1){
				pai[v] = u;
				nivel[v] = nivel[u] + 1;
				dfs(v);
			}
		}
	}

	int LCA(int u, int v){
		if(nivel[u] < nivel[v]) swap(u, v);

		for(int i = MAXL - 1; i >= 0; i--)
			if(nivel[u] - (1 << i) >= nivel[v])
				u = ancestral[u][i];

		if(u == v) return u;

		for(int i = MAXL - 1; i >= 0; i--)
			if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
				u = ancestral[u][i];
				v = ancestral[v][i];
			}

		return pai[u];
	}
};

int main(int argc, char const *argv[])
{
	int N, A, B, x;
	cin >> N;

	par.resize(N/2 + 1);

	Grafo g(N + 1);

	for (int i = 1; i <= N; par[x].push_back(i), ++i)
		cin >> x;

	for (int i = 1; i < N; g.addAresta(A, B), ++i)
		cin >> A >> B;

	for(int i = 0; i < MAXN; i++) pai[i] = nivel[i] = -1;

	for(int i = 0; i <= MAXN; i++)
		for(int j = 0; j < MAXL; j++)
			ancestral[i][j] = -1;

	nivel[1] = 0;
	g.dfs(1);

	for(int i = 1; i <= N; i++) ancestral[i][0] = pai[i];

	for(int j = 1; j < MAXL; j++)
		for(int i = 1; i <= N; i++)
			if(ancestral[i][j - 1] != -1)
				ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];

	long long r = 0LL;

	for(int i = 1; i <= N / 2; i++){
		int a = par[i][0];
		int b = par[i][1];
		r += (long long) (nivel[a] + nivel[b] - (2 * nivel[g.LCA(a, b)]));
	}
	
	cout << r << endl;
	return 0;
}