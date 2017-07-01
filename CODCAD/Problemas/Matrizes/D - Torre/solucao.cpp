#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int matrix[N][N];
	int linha[N], coluna[N];
	for (int i = 0; i < N; ++i)
		linha[i] = coluna[i] = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> matrix[i][j];
			linha[i] += matrix[i][j];
			coluna[j] += matrix[i][j];
		}
	}
	int r = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if((linha[i] + coluna[j] - (2 * matrix[i][j])) > r){
				r = linha[i] + coluna[j] - (2 * matrix[i][j]);
			}
		}
	}

	cout << r << endl;
	return 0;
}