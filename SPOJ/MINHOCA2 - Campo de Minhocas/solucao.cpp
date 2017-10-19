#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(int argc, char const *argv[])
{

	int t = 1;

	while((cin >> N >> M) && (N || M)){
		int cima[M], esquerda[M], direita[M], linha[M];

		for (int i = 0; i < M; ++i)
			cin >> linha[i];

		cima[0] = linha[0];

		for (int i = 1; i < M; i++)
			cima[i] = cima[i - 1] + linha[i];

		for(int i = 1; i < N; i++){
			for(int j = 0; j < M; j ++)
				cin >> linha[j];

			esquerda[0] = cima[0] + linha[0];

			for (int i = 1; i < M; ++i)
				esquerda[i] = max(esquerda[i - 1], cima[i]) + linha[i];

			direita[M - 1] = cima[M - 1] + linha[M - 1];

			for(int i = M - 2; i >= 0; i--)
				direita[i] = max(cima[i], direita[i + 1]) + linha[i];

			for(int i = 0; i < M; i++)
				cima[i] = max(esquerda[i], direita[i]);
		}
		
		cout << "Teste " << t++ << endl;
		cout << cima[M - 1] << endl << endl;
	}

	return 0;
}