//https://codeforces.com/contest/1288/problem/B

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

using namespace std;

ll solve(ll a, ll b)
{
	ll r = 0LL, x = -1LL;
	
	while(r <= b)
	{
		r *= 10;
		r += 9;
		x++;
	}
	
	return x * a;
}

int main(int argc, char** argv)
{
	optimize;

	int T;
	
	ll a, b;
	
	cin >> T;
	
	while(T--)
	{
		cin >> a >> b;
		
		cout << solve(a, b) << endl;
	}
	
	return 0;
}
