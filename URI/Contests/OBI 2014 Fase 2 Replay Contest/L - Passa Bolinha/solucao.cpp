#include <iostream>

using namespace std;

int r = 1;
int N;
int mapa[100][100];
bool visitados[100][100];

void dfs(int i, int j){
	if(visitados[i][j] == false){
		visitados[i][j] = true;
		if((j+1 < N) && (mapa[i][j+1] >= mapa[i][j]) && (visitados[i][j+1] == false)){
			dfs(i, j+1);
			r++;
		}
		if((i+1 < N) && (mapa[i+1][j] >= mapa[i][j]) && (visitados[i+1][j] == false)){
			dfs(i+1, j);
			r++;
		}
		if((j-1 >= 0) && (mapa[i][j-1] >= mapa[i][j]) && (visitados[i][j-1] == false)){
			dfs(i, j-1);
			r++;
		}
		if((i-1 >= 0) && (mapa[i-1][j] >= mapa[i][j]) && (visitados[i-1][j] == false)){
			dfs(i-1, j);
			r++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int I, J;
	cin >> N >> I >> J;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int x;
			cin >> x;
			mapa[i][j] = x;
			visitados[i][j] = false;
		}
	}

	dfs(I-1,J-1);
	cout << r << endl;
	return 0;
}