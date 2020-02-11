#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 1000100
#define MAXL 23

using namespace std;

int N, H[MAXN], R[MAXN], T[MAXN], maior, tam, sum[MAXN];

void pinta(int i, int inicio)
{
	int l, r;

	if(R[i] < T[i])
	{
		l = inicio + R[i] + 1;
		r = inicio + T[i] - 1;

		sum[l]++;
		sum[r + 1]--;
	}
	else
	{
		l = inicio + R[i] + 1;
		r = inicio + H[i];

		sum[l]++;
		sum[r + 1]--;

		l = inicio;
		r = inicio + T[i] - 1;

		sum[l]++;
		sum[r + 1]--;
	}
}

void precalc()
{
	tam = 1825 * maior;

	for(int i = 0; i < N; i++)
		for(int j = 0; j <= tam; j += H[i])
			pinta(i, j);

	for(int i = 0; i <= tam; i++)
		sum[i] += i ? sum[i - 1] : 0;
}

int solve()
{
	precalc();

	for(int i = 0; i <= tam; i++)
		if(!sum[i]) return i;

	return -1;
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> H[i] >> R[i] >> T[i];
		maior = max(maior, H[i]);
	}

	int ans = solve();

	if(ans != -1)
		cout << ans << endl;
	else
		cout << "impossible" << endl;

	return 0;
}