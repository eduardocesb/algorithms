#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 100100

using namespace std;

vector<int> cidades_do_ciclo;
bool ta_no_ciclo[MAXN];
int chefe[MAXN];
int posicao[MAXN];
int tam_ciclo;
int grafo[MAXN];

vector<int> grafo_reverso [MAXN];

int distancia_ate_o_ciclo(int u){
	return posicao[u] - posicao[chefe[u]];
}

int distancia(int a, int b){
	if(posicao[a] > posicao[b])
		return tam_ciclo - posicao[a] + posicao[b];
	return posicao[b] - posicao[a];
}

void dfs(int u){

	//cout << u + 1 << ' ' << posicao[u] << ' ' << chefe[u] + 1 << endl;

	for (int i = 0; i < grafo_reverso[u].size(); ++i)
	{	
		int v = grafo_reverso[u][i];

		if(ta_no_ciclo[v]) continue;

		posicao[v] = posicao[u] + 1;

		chefe[v] = chefe[u];

		dfs(v);
	}
}

int main(int argc, char const *argv[])
{
	optimize;
	int N, v;

	cin >> N;

	for (int u = 0; u < N; ++u)
	{
		cin >> v;

		grafo[u] = v - 1;
		grafo_reverso[v - 1].push_back(u);
	}

	for (int u = 0; u < N; ++u)
		if(grafo_reverso[u].size() > 1){

			ta_no_ciclo[u] = true;

			cidades_do_ciclo.push_back(u);

			int v = grafo[u];
			while(u != v){
				ta_no_ciclo[v] = true;
				cidades_do_ciclo.push_back(v);
				v = grafo[v];
			}

			break;
		}

	tam_ciclo = cidades_do_ciclo.size();

	for (int i = 0; i < tam_ciclo; ++i)
	{
		int v = cidades_do_ciclo[i];
		chefe[v] = v;
		posicao[v] = i;

		dfs(v);
	}

	int Q, a, b;

	// for (int i = 0; i < N; ++i)
	// {
	// 	cout << posicao[i] << ' ' << chefe[i] + 1 << endl;
	// }

	for (cin >> Q; Q ; Q--)
	{
		cin >> a >> b;
		a--, b--;

		if(chefe[a] == chefe[b])
			cout << abs(posicao[a] - posicao[b]) << endl;
		else{
			int da = distancia_ate_o_ciclo(a);
			int db = distancia_ate_o_ciclo(b);

			// cout << da << ' ' << db << endl;
			// cout << chefe[a] + 1 << ' ' << chefe[b] + 1 << endl;
			// cout << distancia(chefe[a], chefe[b]) << ' ' << distancia(chefe[b], chefe[a]) << endl;
			int ponto_de_encontro_a = max(da, db + distancia(chefe[b], chefe[a]));
			int ponto_de_encontro_b = max(db, da + distancia(chefe[a], chefe[b]));

			cout << min(ponto_de_encontro_a, ponto_de_encontro_b) << endl;
		}
	}
	return 0;
}