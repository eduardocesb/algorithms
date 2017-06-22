#include <iostream>

using namespace std;
bool visitados[101][101];
int mapa[101][101];
int r = 0;
int N;

void passa_bolinha(int I, int J){
	r++;
	visitados[I][J] = true;
	if(I < N && visitados[I+1][J] == false && mapa[I+1][J] >= mapa[I][J]){
		passa_bolinha(I+1, J);
	}

	if(I > 1 && visitados[I-1][J] == false && mapa[I-1][J] >= mapa[I][J]){
		passa_bolinha(I-1, J);
	}

	if(J < N && visitados[I][J+1] == false && mapa[I][J+1] >= mapa[I][J]){
		passa_bolinha(I, J+1);
	}

	if(J > 1 && visitados[I][J-1] == false && mapa[I][J-1] >= mapa[I][J]){
		passa_bolinha(I, J-1);
	}
}

int main(int argc, char const *argv[])
{
	int I, J;
	cin >> N >> I >> J;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> mapa[i][j];
			visitados[i][j] = false;
		}
	}

	passa_bolinha(I, J);
	cout << r << endl;
	return 0;
}