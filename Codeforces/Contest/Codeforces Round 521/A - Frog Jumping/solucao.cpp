#include <bits/stdc++.h>
#define ll long long
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

ll solve(ll a, ll b, ll k)
{
	ll meio = k / 2LL;
	ll x = a * (k - meio);
	x -= meio * b;	
	return x;
}

int main(int argc, char** argv)
{
	optimize;
	
	int t;
	
	cin >> t;
	
	ll a, b, k;
	
	while(t--)
	{
		cin >> a >> b >> k;
		cout << solve(a, b, k) << endl;
	}
	
	return 0;
}