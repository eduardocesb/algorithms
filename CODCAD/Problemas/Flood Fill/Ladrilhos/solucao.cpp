#include <bits/stdc++.h>
#define MAXN 210
#define INFINITO 1000000

using namespace std;

int mapa[MAXN][MAXN];
bool visitados[MAXN][MAXN];
int N, M;

bool pode_ir(int i, int j, int i_, int j_){
	return (i >= 0 && j >= 0 && i < N && j < M && !visitados[i][j] && mapa[i][j] == mapa[i_][j_]);
}

int DFS(int i, int j){
	int r = 0;
	visitados[i][j] = true;

	if(pode_ir(i + 1, j, i , j))
		r += 1 + DFS(i + 1, j);

	if(pode_ir(i - 1, j, i , j))
		r += 1 + DFS(i - 1, j);

	if(pode_ir(i, j + 1, i , j))
		r += 1 + DFS(i, j + 1);

	if(pode_ir(i, j - 1, i , j))
		r += 1 + DFS(i, j - 1);

	return r;
}

int main(int argc, char const *argv[])
{
	memset(visitados, false, sizeof(visitados));

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> mapa[i][j];

	int r = INFINITO;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if(!visitados[i][j])
				r = min(r, DFS(i, j));

	cout << r + 1 << endl;
	return 0;
}