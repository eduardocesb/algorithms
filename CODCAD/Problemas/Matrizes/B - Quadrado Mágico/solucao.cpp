#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int matrix[N][N];
	int linha[N], coluna[N], diagonal_principal = 0, diagonal_secundaria = 0;
	for (int i = 0; i < N; ++i)
		linha[i] = coluna[i] = 0;

	for (int i = 0; i < N; ++i)
	{
		linha[i] = 0;
		for (int j = 0; j < N; ++j)
		{
			cin >> matrix[i][j];
			linha[i] += matrix[i][j];
			coluna[j] += matrix[i][j];
			if(i == j){
				diagonal_principal += matrix[i][j];
			}

			if(i + j == N - 1){
				diagonal_secundaria += matrix[i][j];
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if(linha[i] != diagonal_principal || linha[i] != diagonal_secundaria || coluna[i] != diagonal_principal || coluna[i] != diagonal_secundaria){
			cout << -1 << endl;
			return 0;
		}
		for (int j = 0; j < N; ++j)
		{
			if(linha[i] != coluna[j]){
				cout << -1 << endl;
				return 0;
			}
		}
		
	}

	cout << diagonal_principal << endl;
	return 0;
}