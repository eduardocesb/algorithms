#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

ll solve(ll k, ll n, ll a, ll b)
{
	int ini = 0, fim = n, meio;

	ll r = -1LL;

	while(ini <= fim)
	{
		meio = (ini + fim) / 2;

		if((a * meio) + (b * (n - meio)) < k)
		{
			r = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	return r;
}

int main(int argc, char** argv)
{
	optimize;

	int Q, k, n, a, b;

	cin >> Q;

	while(Q--)
	{
		cin >> k >> n >> a >> b;

		cout << solve(k, n, a, b) << endl;
	}

	return 0;
}
