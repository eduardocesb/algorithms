#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 100100
#define MOD 1000000007
#define MAXL 22

using namespace std;

ll fib[MAXN];

ll solve(int N)
{
	if(fib[N] != -1) return fib[N];
	return fib[N] = (solve(N - 1) + solve(N - 2)) % MOD;
}

int main(int argc, char const *argv[])
{
	for(int i = 0; i < MAXN; i++) fib[i] = -1LL;

	fib[0] = fib[1] = 1;

	optimize;

	string S;

	cin >> S;

	int N = S.length();

	bool ok = true;
	
	int qtd = 0;

	ll r = 1LL;

	for(int i = 0; i < N; i++)
	{
		if(S[i] != 'n') r = (solve(qtd) * r) % MOD, qtd = 0;
		else qtd++;

		ok *= (S[i] != 'm' && S[i] != 'w');
	}

	if(!ok)
	{
		cout << 0 << endl;
		return 0;
	}

	r = (solve(qtd) * r) % MOD;
	qtd = 0;

	for(int i = 0; i < N; i++)
		if(S[i] != 'u') r = (solve(qtd) * r) % MOD, qtd = 0;
		else qtd++;

	r = (solve(qtd) * r) % MOD;

	cout << r << endl;

	return 0;
}