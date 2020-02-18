//https://codeforces.com/contest/1304/problem/C
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 110

using namespace std;

int T[MAXN], L[MAXN], H[MAXN], N, M;

bool solve()
{
	int instante = 0;

	int l = M - T[0], r = M + T[0];

	for(int i = 0; i < N; i++)
	{
		if(H[i] < l || r < L[i]) return false;

		l = max(l, L[i]);
		r = min(r, H[i]);

		l -= T[i + 1] - T[i];
		r += T[i + 1] - T[i];
	}

	return true;
}

int main(int argc, char const *argv[])
{
	optimize;

	int Q;

	cin >> Q;

	while(Q--)
	{
		cin >> N >> M;

		for(int i = 0; i < N; i++)
			cin >> T[i] >> L[i] >> H[i];

		cout << (solve() ? "YES" : "NO") << endl;
	}
	
	return 0;
}