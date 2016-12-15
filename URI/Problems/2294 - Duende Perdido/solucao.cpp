#include <iostream>
#include <queue>

using namespace std;

int N = 0, M = 0;

int mapa[10][10];
bool visitados[10][10];

int bfs(int I, int J){
	queue<pair<pair<int,int>, int> > fila;
	visitados[I][J] = true;
	fila.push(make_pair(make_pair(I, J), 0));
	int r = 0;
	while(!fila.empty()){
		pair<pair<int, int>, int> da_vez = fila.front();
		fila.pop();
		pair<int, int> coordenada = da_vez.first;
		int i = coordenada.first;
		int j = coordenada.second;
		r = da_vez.second;
		if(mapa[i][j] == 0){
			break;
		}

		r++;
		if(i < N-1 && visitados[i+1][j] == false && mapa[i+1][j] != 2){
			fila.push(make_pair(make_pair(i+1, j), r));
			visitados[i+1][j] = true;
		}
		if(i > 0 && visitados[i-1][j] == false && mapa[i-1][j] != 2){
			fila.push(make_pair(make_pair(i-1, j), r));
			visitados[i-1][j] = true;
		}
		if(j < M-1 && visitados[i][j+1] == false && mapa[i][j+1] != 2){
			fila.push(make_pair(make_pair(i, j+1), r));
			visitados[i][j+1] = true;
		}
		if(j > 0 && visitados[i][j-1] == false && mapa[i][j-1] != 2){
			fila.push(make_pair(make_pair(i, j-1), r));
			visitados[i][j-1] = true;
		}
	}
	return r;
}

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	int inicioI, inicioJ;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int x;
			cin >> x;
			visitados[i][j] = false;
			if(x == 3){
				inicioI = i;
				inicioJ = j;
			}
			mapa[i][j] = x;
		}
	}
	cout << bfs(inicioI, inicioJ) << endl;
	return 0;
}