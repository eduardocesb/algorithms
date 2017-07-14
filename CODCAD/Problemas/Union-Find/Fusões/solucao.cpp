#include <iostream>
#define MAXN 100010

using namespace std;

int pai[MAXN];
int peso[MAXN];

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
		pai[x] = y;
		peso[y]++;
	}else{
		pai[y] = x;
		peso[x]++;
	}
}

int main(int argc, char const *argv[])
{
	int N, K, X, Y;
	char O;
	cin >> N >> K;
	for (int i = 0; i <= N; ++i)
	{
		peso[i] = 0;
		pai[i] = i;
	}

	for (int i = 0; i < K; ++i)
	{
		cin >> O >> X >> Y;
		if(O == 'C')
			cout << (find(X) == find(Y) ? 'S' : 'N') << endl;
		else
			join(X, Y);
	}
	return 0;
}