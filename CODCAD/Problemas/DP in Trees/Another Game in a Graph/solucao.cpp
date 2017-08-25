#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int dp[MAXN][2];
int pai[MAXN];
int peso[MAXN];
bool visitados[MAXN];

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
		visinhos[v1].push_back(v2);
		visinhos[v2].push_back(v1);
	}

	int solve(){

		stack<int> pilha;
		pilha.push(0);

		while(!pilha.empty()){
			int u = pilha.top();

			bool achou = false;

			if(!visitados[u]){

				list<int>::iterator it = visinhos[u].begin();

				for(; it != visinhos[u].end(); it++){
					if(pai[u] == *it) continue;
					pai[*it] = u;

					achou = true;

					pilha.push(*it);
				}
				visitados[u] = true;
			}

			if(!achou){
				dp[pai[u]][false] += max(0, max(dp[u][true], dp[u][false]));
				dp[pai[u]][true] += max(0, dp[u][false]);
				pilha.pop();
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	memset(visitados, false, sizeof(visitados));

	int N, A, B;
	cin >> N;

	for (int i = 0; i <= N; ++i)
		dp[i][0] = pai[i] = 0;
	pai[0] = N;

	Grafo g(N);

	for (int i = 1; i < N; ++i)
	{
		cin >> A >> B;
		g.addAresta(A - 1, B - 1);
	}

	for (int i = 0; i < N; dp[i][1] = peso[i], ++i)
		cin >> peso[i];

	g.solve();
	cout << max(dp[0][0], dp[0][1]) << endl;
	return 0;
}