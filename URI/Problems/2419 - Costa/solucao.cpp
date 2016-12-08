#include <iostream>

using namespace std;

char mapa[1001][1001];
int N, M;

bool tem_costa(int i, int j){

	if(j == 0){
		return true;
	}
	if(i == 0){
		return true;
	}
	if(j == M-1){
		return true;
	}
	if(i == N-1){
		return true;
	}

	if(i > 0 && mapa[i-1][j] == '.'){
		return true;
	}
	if(i < N-1 && mapa[i+1][j] == '.'){
		return true;
	}

	if(j > 0 && mapa[i][j-1] == '.'){
		return true;
	}
	if(j < M-1 && mapa[i][j+1] == '.'){
		return true;
	}

	return false;
}

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char x;
			cin >> x;
			mapa[i][j] = x;
		}
	}

	int r = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if(mapa[i][j] == '.'){
				continue;
			}
			if(tem_costa(i, j)){
				r++;
			}
		}
	}

	cout << r << endl;
	return 0;
}