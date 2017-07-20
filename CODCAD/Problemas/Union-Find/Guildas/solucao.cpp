#include <iostream>
#define MAXN 100010

using namespace std;

int pai[MAXN];
int peso[MAXN];
int pontos[MAXN];
int pai_r;

int find(int x){
	if(pai[x] == x)
		return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y)
		return;
	if(peso[x] < peso[y]){
		if(pai_r == x)
			pai_r = y;
		//O pai de y agora é x...
		pai[x] = y;
		//Os pontos de x aumentam com os pontos de y...
		pontos[y] += pontos[x];
		peso[y]++;
	}else{
		if(pai_r == y)
			pai_r = x;
		pai[y] = x;
		pontos[x] += pontos[y];
		peso[x]++;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, Q, A, B;
	while((cin >> N >> M) && (N != 0 || M != 0)){
		peso[0] = pai[0] = 0;
		for (int i = 1; i <= N; ++i)
		{
			peso[i] = 0;
			pai[i] = i;
			cin >> pontos[i];
		}
		pai_r = 1;
		int r = 0;
		for (int i = 0; i < M; ++i)
		{
			cin >> Q >> A >> B;
			if(Q == 1)
				join(A, B);
			else{
				A = find(A);
				B = find(B);
				if(A == pai_r && pontos[A] > pontos[B])
					r++;
				else if(B == pai_r && pontos[B] > pontos[A])
					r++;
			}
		}
		cout << r << endl;
	}
	return 0;
}