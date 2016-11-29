#include <iostream>

using namespace std;

int M, N;


int main(int argc, char const *argv[])
{
	cin >> M >> N;
	char mapa[M][N];
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char x;
			cin >> x;
			mapa[i][j] = x;
		}
	}
	int r = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(mapa[i][j] == '#'){
				if(i == 0 || j == 0 || i == M-1 || j == N-1){
					r++;
				}else if(mapa[i-1][j] == '.'){
					r++;
				}else if(mapa[i+1][j] == '.'){
					r++;
				}else if(mapa[i][j-1] == '.'){
					r++;
				}else if(mapa[i][j+1] == '.'){
					r++;
				}
			}
		}
	}
	cout << r << endl;
	return 0;
}