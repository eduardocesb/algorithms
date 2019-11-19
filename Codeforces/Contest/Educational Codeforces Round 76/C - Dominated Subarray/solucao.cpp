#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 200100
#define MAXL 22

using namespace std;

int f[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

	int N, T, r, x;

	cin >> T;

	while(T--)
	{
		cin >> N;

		for(int i = 0; i <= N; i++) f[i] = -INF;

		r = INF;

		for(int i = 0; i < N; i++)
		{
			cin >> x;

			r = min(r, i - f[x]);

			f[x] = i;
		}

		cout << (r == INF ? -1 : r + 1) << endl;
	}
	

	return 0;
}
