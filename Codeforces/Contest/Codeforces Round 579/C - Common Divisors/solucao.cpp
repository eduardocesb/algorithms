#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 100010

using namespace std;

ll MDC(ll a, ll b)
{
	return !b ? a : MDC(b, a % b);
}

int main(int argc, char const *argv[])
{
	optimize;

	int N; 

	cin >> N;

	ll x, mdc;

	for(int i = 0; i < N; i++)
	{
		cin >> x;

		if(!i) mdc = x;

		mdc = MDC(mdc, x);
	}

	int root = sqrt(mdc), r = 0;

	// cout << root << " -- " << mdc << endl;

	for(int i = 1; i <= root; i++)
	{
		if(mdc % i != 0) continue;
		r++;
		if(i != (mdc / i)) r++;
	}

	cout << r << endl;

	
	return 0;
}