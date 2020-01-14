//https://codeforces.com/contest/1271/problem/A

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 2000000000
#define MAXN 200020

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	ll r = 0LL;

	for(int i = 0; i <= d; i++)
		r = max(r, 1LL * ((min(a, i) * e) + (min({d - i, b, c}) * f)));

	cout << r << endl;

	return 0;
}