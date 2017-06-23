#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	char mapa[N][M];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> mapa[i][j];
		}
	}
	int r = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if(mapa[i][j] == '#'){
				if(i == 0 || j == 0 || i == N-1 || j == M-1){
					r++;
				}else if(mapa[i-1][j] == '.' || mapa[i+1][j] == '.' || mapa[i][j-1] == '.' || mapa[i][j+1] == '.'){
					r++;
				}
			}
		}
	}
	cout << r << endl;
	return 0;
}