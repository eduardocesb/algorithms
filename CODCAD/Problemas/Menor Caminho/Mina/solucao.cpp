#include <iostream>
#include <queue>

#define MAXN 110
#define INFINITO 10000010
#define ii pair<int, int>
#define iii pair<int, ii>

using namespace std;

int N;
int mapa[MAXN][MAXN], distancia[MAXN][MAXN];

int dijkstra(){
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	distancia[0][0] = 0;
	pq.push(make_pair(0, make_pair(0, 0)));
	int d, i, j, i_, j_;
	while(!pq.empty()){
		d = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
		pq.pop();
		if(distancia[i][j] == INFINITO)
			continue;
		i_ = i + 1, j_ = j;

		if(i_ > -1 && i_ < N && j_ > -1 && j_ < N && distancia[i][j] + mapa[i_][j_] < distancia[i_][j_]){
			distancia[i_][j_] = distancia[i][j] + mapa[i_][j_];
			pq.push(make_pair(distancia[i_][j_], make_pair(i_, j_)));
		}

		i_ = i - 1, j_ = j;

		if(i_ > -1 && i_ < N && j_ > -1 && j_ < N && distancia[i][j] + mapa[i_][j_] < distancia[i_][j_]){
			distancia[i_][j_] = distancia[i][j] + mapa[i_][j_];
			pq.push(make_pair(distancia[i_][j_], make_pair(i_, j_)));
		}

		i_ = i, j_ = j + 1;

		if(i_ > -1 && i_ < N && j_ > -1 && j_ < N && distancia[i][j] + mapa[i_][j_] < distancia[i_][j_]){
			distancia[i_][j_] = distancia[i][j] + mapa[i_][j_];
			pq.push(make_pair(distancia[i_][j_], make_pair(i_, j_)));
		}

		i_ = i, j_ = j - 1;

		if(i_ > -1 && i_ < N && j_ > -1 && j_ < N && distancia[i][j] + mapa[i_][j_] < distancia[i_][j_]){
			distancia[i_][j_] = distancia[i][j] + mapa[i_][j_];
			pq.push(make_pair(distancia[i_][j_], make_pair(i_, j_)));
		}
	}

	return distancia[N -1][N - 1];
}


int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> mapa[i][j];
			distancia[i][j] = INFINITO;
		}
	}

	cout << dijkstra() << endl;
	return 0;
}