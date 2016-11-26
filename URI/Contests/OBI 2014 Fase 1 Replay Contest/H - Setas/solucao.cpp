#include <iostream>

using namespace std;

int r = 0;
int N;
char mapa[500][500];
bool visitados[500][500];

bool sai(int i, int j){

	if(i == 0 && mapa[i][j] == 'A'){
		return true;
	}else if(j == 0 && mapa[i][j] == '<'){
		return true;
	}else if(i == N-1 && mapa[i][j] == 'V'){
		return true;
	}else if(j == N-1 && mapa[i][j] == '>'){
		return true;
	}else{
		return false;
	}
}

void dfs(int i, int j){
	if(!visitados[i][j]){
		r++;
		if(i > 0 && mapa[i-1][j] == 'V' && visitados[i-1][j] == false){
			//cout << i-1 << " " << j << endl;
			dfs(i-1,j);
		}
		if(j > 0 && mapa[i][j-1] == '>' && visitados[i][j-1] == false){
			//cout << i << " " << j-1 << endl;
			dfs(i, j-1);
		}
		if(i < N-1 && mapa[i+1][j] == 'A' && visitados[i+1][j] == false){
			//cout << i+1 << " " << j << endl;
			dfs(i+1,j);
		}
		if(j < N-1 && mapa[i][j+1] == '<' && visitados[i][j+1] == false){
			//cout << i << " " << j+1 << endl;
			dfs(i, j+1);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char x;
			cin >> x;
			mapa[i][j] = x;
			visitados[i][j] = false;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(sai(i,j)){
				//cout << i << " " << j << endl;
				dfs(i,j);
			}
		}
	}
	r = (N*N) - r;
	cout << r << endl;
	return 0;
}