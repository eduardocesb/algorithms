#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define ld long double
#define MAXN 100100
#define MAXL 23

using namespace std;

ll N, G, B;

ll solve()
{
	ll ans = 0LL;

	ll meio = (N + 1) / 2;

	ll tam = G + B;
	ll x = (meio / G);

	if(!(meio % G)) x--;

	ans = (tam * x);

	ll qtd = x * G;

	ans += meio - qtd;

	return max(ans, N);
}

int main(int argc, char const *argv[])
{
	optimize;

	int T;

	cin >> T;

	while(T--)
	{
		cin >> N >> G >> B;

		cout << solve() << endl;
	}
	
	return 0;
}