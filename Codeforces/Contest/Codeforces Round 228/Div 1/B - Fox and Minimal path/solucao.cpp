//https://codeforces.com/problemset/problem/388/B
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 20000000000
#define ll long long
#define pii pair<int, int>
#define MAXK 1000000007
#define MAXN 10010

using namespace std;

bool mapa[MAXN][MAXN];
int pot[31], T;
vector<int> tamanhos;
ll K;
int disponivel = 3;

void solve()
{
	if(tamanhos[0] == 0)
	{
		mapa[1][2] = mapa[2][1] = true;
		return;
	}


	int nivel = 1;

	while(nivel <= tamanhos[0])
	{
		if(nivel == 1)
		{
			disponivel += 2;
			mapa[1][3] = mapa[3][1] = mapa[1][4] = mapa[4][1] = true;
		}
		else
		{
			disponivel += 2;
			int ant = 2 * nivel;
			int atual = ant + 2;

			mapa[ant][atual] = mapa[atual][ant] = true;
			mapa[ant][atual - 1] = mapa[atual - 1][ant] = true;
			mapa[ant - 1][atual] = mapa[atual][ant - 1] = true;
			mapa[ant - 1][atual - 1] = mapa[atual - 1][ant - 1] = true;
		}

		nivel++;
	}

	mapa[disponivel - 1][2] = mapa[2][disponivel - 1] = mapa[disponivel - 2][2] = mapa[2][disponivel - 2] = true;

	for(int i = 1; i < (int)tamanhos.size(); i++)
	{
		int atual = 2 * (tamanhos[i] + 1);

		if(tamanhos[i] == 0)
		{
			mapa[1][disponivel] = mapa[disponivel][1] = true;
		}
		else
		{
			mapa[atual][disponivel] = mapa[disponivel][atual] = true;
			mapa[atual - 1][disponivel] = mapa[disponivel][atual - 1] = true;
		}

		disponivel++;

		while(++tamanhos[i] < tamanhos[0])
		{
			mapa[disponivel][disponivel - 1] = mapa[disponivel - 1][disponivel] = true;
			disponivel++;
		}

		mapa[disponivel - 1][2] = mapa[2][disponivel - 1] = true;
	}
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> K;

	pot[0] = 1;

	for(int i = 1; i < 31; i++)
		pot[i] = 2 * pot[i - 1];

	int i = 31;

	while(K)
	{
		i--;

		if(K < pot[i]) continue;

		K -= pot[i];

		tamanhos.push_back(i);
	}

	solve();

	cout << disponivel << endl;
	for(int i = 1; i <= disponivel; i++)
		for(int j = 1; j <= disponivel; j++)
			cout << (mapa[i][j] ? "Y" : "N") << (j == disponivel ? "\n" : "");

	return 0;
}