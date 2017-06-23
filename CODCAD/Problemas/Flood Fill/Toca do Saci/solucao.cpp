#include <iostream>

#define MAXN 1001

using namespace std;

int mapa[MAXN][MAXN];

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	int x, y;
	for(int i = 0; i < N ; i++){
		for(int j = 0; j < M; j++){
			cin >> mapa[i][j];
			if(mapa[i][j] == 3){
				x = i;
				y = j;
			}
		}
	}

	int r = 1;
	while(true){
		r++;
		if(x > 0 && mapa[x-1][y] == 1){
			x--;
			mapa[x][y] = 0;
		}else if(x < N-1 && mapa[x+1][y] == 1){
			x++;
			mapa[x][y] = 0;
		}else if(y > 0 && mapa[x][y-1] == 1){
			y--;
			mapa[x][y] = 0;
		}else if(y < M-1 && mapa[x][y+1] == 1){
			y++;
			mapa[x][y] = 0;
		}else if(x > 0 && mapa[x-1][y] == 2){
			break;
		}else if(x < N-1 && mapa[x+1][y] == 2){
			break;
		}else if(y > 0 && mapa[x][y-1] == 2){
			break;
		}else if(y < M-1 && mapa[x][y+1] == 2){
			break;
		}
	}

	cout << r << endl;

	return 0;
}