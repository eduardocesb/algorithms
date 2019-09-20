#include <bits/stdc++.h>
#define ll long long
#define MAXT 1000000000000000000

using namespace std;

bool ok(ll a, ll b, ll c, ll times)
{
	return (times <= a && times <= b && (3 * times) <= (a + b + c));
}

ll solve(ll a, ll b, ll c)
{	
	ll l = 0LL, r = MAXT, m, resp;
	
	while(l <= r)
	{
		m = (l + r) >> 1;
		
		if(ok(a, b, c, m))
		{
			resp = m;
			l = m  + 1;
		}
		else
			r = m - 1;
	}
	
	return resp;
}

int main(int argc, char** argv)
{
	int N;

	cin >> N;
		
	ll a, b, c;
	
	while(N--)
	{
		cin >> a >> b >> c;
		
		cout << solve(a, b, c) << endl;
	}
	
	return 0;
}
