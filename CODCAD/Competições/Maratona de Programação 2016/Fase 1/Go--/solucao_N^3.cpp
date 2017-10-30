/*
	Solução em O(N³)
*/
#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 510

using namespace std;

int pretas[MAXN][MAXN];
int brancas[MAXN][MAXN];
int N, P;

void precalc(int mapa[MAXN][MAXN])
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			mapa[i][j] += mapa[i - 1][j] + mapa[i][j - 1] - mapa[i - 1][j - 1];
}

int qtd(int mapa[MAXN][MAXN], int i, int j, int k)
{
	return (mapa[i + k][j + k] - mapa[i + k][j - 1] - mapa[i - 1][j + k] + mapa[i - 1][j - 1]);
}

int main(int argc, char** argv)
{
	optimize;

	memset(pretas, 0, sizeof(pretas));
	memset(brancas, 0 , sizeof(brancas));

	int x, y;

	cin >> N >> P;

	//Leio as pecas pretas...
	for(int i = 0; i < P; i++) cin >> x >> y, pretas[x][y] = 1;
	//Leio as pecas brancas...
	for(int i = 0; i < P; i++) cin >> x >> y, brancas[x][y] = 1;

	//Faco o pre-calculo nas pecas pretas...
	precalc(pretas);
	//Faco o pre-calculo nas pecas brancas...
	precalc(brancas);

	int p = 0, b = 0;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			for(int k = 0; max(i, j) + k <= N; k++)
			{
				//Quantidade de pecas pretas e brancas que existem no quadrado
				//de origem na posicao 'i' 'j' e com lado k...
				int qtd_pretas = qtd(pretas, i, j, k);
				int qtd_brancas = qtd(brancas, i, j, k);

				//Se existe peca preta e nao existe peca branca...
				//Aumenta em 1 a quantidade de areas pretas
				if(qtd_pretas && !qtd_brancas) p++;
				//O mesmo acontece para as pecas brancas...
				else if(qtd_brancas && !qtd_pretas) b++;
			}

	cout << p << ' ' << b << endl;
	return 0;
}
