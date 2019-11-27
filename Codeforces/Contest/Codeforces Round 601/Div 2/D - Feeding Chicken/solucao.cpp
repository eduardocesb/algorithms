//https://codeforces.com/contest/1255/problem/D
//Solution O(R * C)

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 110

using namespace std;

char m[MAXN][MAXN];
int L, C, T, G, A;

vector<char> Galinha;

void solve()
{
	int k = A / G, atual = 0, galinha = 0, passo = 1, j = 0;

	for(int i = 0; i < L; i++)
		while(true)
		{
			if(m[i][j] == 'R' && atual == k)
			{
				galinha++;
				A -= k;
				G--;
				k = A / G;
				atual = 0;
			}

			atual += m[i][j] == 'R';

			m[i][j] = Galinha[galinha];

			j += passo;

			if(j >= C)
			{
				j = C - 1;
				passo = -1;
				break;
			}
			else if(j < 0)
			{
				j = 0;
				passo = 1;
				break;
			}
		}

	for(int i = 0; i < L; i++)
		for(int j = 0; j < C; j++)
			cout << m[i][j] << (j == C - 1 ? "\n" : "");
}

int main(int argc, char const *argv[])
{
	optimize;

	for(int i = 0; i < 10; i++) Galinha.push_back('0' + i);
	for(int i = 0; i < 26; i++) Galinha.push_back('a' + i);
	for(int i = 0; i < 26; i++) Galinha.push_back('A' + i);

	cin >> T;

	while(T--)
	{
		cin >> L >> C >> G;

		A = 0;

		for(int i = 0; i < L; i++)
			for(int j = 0; j < C; j++)
			{
				cin >> m[i][j];
				A += (m[i][j] == 'R');
			}

		solve();
	}

	return 0;
}