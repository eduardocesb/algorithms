#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 55

using namespace std;

unordered_map<string, int> mapa;
int N, M;
char m[MAXN][MAXN];

string linha(int i, int inicio, int fim)
{
	string r = "";
	for(; inicio <= fim; inicio++)
		r += m[i][inicio];
	return r;
}

string coluna(int j, int inicio, int fim)
{
	string r = "";
	for(; inicio <= fim; inicio++)
		r += m[inicio][j];
	return r;
}

void precalc()
{
	//precalcula as linhas...
	for(int d = 1; d < M; d++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j + d < M; j++)
				mapa[linha(i, j, j + d)]++;

	//precalcula as colunas
	for(int d = 1; d < N; d++)
		for(int i = 0; i + d < N; i++)
			for(int j = 0; j < M; j++)
				mapa[coluna(j, i, i + d)]++;
}

int main(int argc, char** argv)
{
	optimize;
	int T, Q;
	string x;

	cin >> T;

	while(T--)
	{
		mapa.clear();
		cin >> N >> M;

		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
			{
				cin >> m[i][j];
				x = m[i][j];
				mapa[x]++;
			}

		precalc();

		cin >> Q;

		while(Q-- && cin >> x)
			cout << mapa[x] << endl;
	}

	return 0;
}
