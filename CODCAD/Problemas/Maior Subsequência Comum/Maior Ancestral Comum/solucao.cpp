#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 1010

using namespace std;

int s1[MAXN], s2[MAXN];
int tab[MAXN][MAXN];

int lcs(int a, int b){
	if(tab[a][b] != -1) return tab[a][b];
	if(a == 0 || b == 0) return tab[a][b] = 0;
	if(s1[a] == s2[b]) return 1 + lcs(a - 1, b - 1);
	return tab[a][b] = max(lcs(a - 1, b), lcs(a, b - 1));
}

int main(int argc, char const *argv[])
{
	memset(tab, -1, sizeof(tab));
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) cin >> s1[i];
	for (int i = 1; i <= M; ++i) cin >> s2[i];

	cout << N - lcs(N, M) << ' ' << M - lcs(N, M) << endl;
	return 0;
}