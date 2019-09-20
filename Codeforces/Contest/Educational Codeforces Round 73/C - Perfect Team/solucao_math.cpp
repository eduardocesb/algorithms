#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll a, ll b, ll c)
{
	return min(min(a, b), ((a + b + c) / 3));
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
