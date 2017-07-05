#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int G, P;
	cin >> G >> P;
	while(G != 0 || P != 0){
		int ordem_de_chegada[G][P];
		int pontos[P];
		int x;
		for (int i = 0; i < G; ++i)
		{
			for (int j = 0; j < P; ++j)
			{
				ordem_de_chegada[i][j] = 0;
			}
		}
		//Para cada grande premio...
		for (int j = 0; j < G; ++j)
		{
			//Pegar a ordem de chegada de cada piloto...
			for (int i = 0; i < P; ++i)
			{
				cin >> x;
				ordem_de_chegada[j][x - 1] = i;
			}
		}

		// for (int i = 0; i < G; ++i)
		// {
		// 	for (int j = 0; j < P; ++j)
		// 	{
		// 		cout << ordem_de_chegada[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		int sistemas_de_pontuacao;
		cin >> sistemas_de_pontuacao;
		for (int i = 0; i < sistemas_de_pontuacao; ++i)
		{
			for (int k = 0; k < P; ++k)
			{
				pontos[k] = 0;
			}
			//Quantidade de pilotos premiados...
			int premiados;
			cin >> premiados;
			int maximo = 0;
			for (int j = 0; j < premiados; ++j)
			{
				cin >> x;
				//Para cada grande premio...
				for (int k = 0; k < G; ++k)
				{
					pontos[ordem_de_chegada[k][j]] += x;
					maximo = max(maximo, pontos[ordem_de_chegada[k][j]]);
				}

			}

			for (int i = 0; i < P; ++i)
			{
				if(pontos[i] == maximo)
					cout << i + 1 << ' ';
			}
			cout << endl;
		}

		cin >> G >> P;
	}
	return 0;
}