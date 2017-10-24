#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0);
#define MAXN 330
#define INFINITO 1000000000
#define pii pair<int, int>
#define piii pair<int, pii>
#define mp make_pair

using namespace std;

int di[] = { -1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

int N;
int mapa[MAXN][MAXN];
int visitados[MAXN][MAXN];
int cont;

int bfs(int maior)
{
	queue<piii> fila;

	++cont;

	if(mapa[0][0] <= maior)
		fila.push(mp(1, mp(0, 0)));

	while(!fila.empty())
	{
		int i = fila.front().second.first;
		int j = fila.front().second.second;
		int d = fila.front().first;

		fila.pop();

		if(i == N - 1 && j == N - 1)
			return d;

		if(visitados[i][j] == cont)
			continue;

		visitados[i][j] = cont;

		for(int k = 0; k < 4; k++)
		{
			int i_ = i + di[k];
			int j_ = j + dj[k];

			if(i_ < N && j_ < N && i_ > -1 && j_ > -1)
			{
				if(mapa[i_][j_] <= maior)
					fila.push(mp(d + 1, mp(i_, j_)));
			}
		}
	}

	return -1;
}

int main(int argc, char** argv)
{
	optimize;

	cin >> N;

	int m = 0;

	for(int i = 0; i < N; i++) for(int j = 0; j < N; m = max(m, mapa[i][j]), j++) cin >> mapa[i][j];

	int inicio = 1, fim = m, meio;

	int maximo, tam;

	while(inicio <= fim)
	{
		meio = (inicio + fim) / 2;

		int r = bfs(meio);

		if(r == -1)
			inicio = meio + 1;
		else
			fim = meio - 1, tam = r, maximo = meio;
	}

	cout << maximo << ' ' << tam << endl;
	return 0;
}
