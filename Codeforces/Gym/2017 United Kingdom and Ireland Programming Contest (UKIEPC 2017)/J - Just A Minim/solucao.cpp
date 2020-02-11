#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 100100
#define MAXL 23

using namespace std;

double value(int x)
{
	return x ? 1.0 / x : 2.0;
}

int main(int argc, char const *argv[])
{
	optimize;

	long double ans = 0;

	int N, x;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> x;
		ans += value(x);
	}

	cout << setprecision(4) << fixed << ans << endl;

	return 0;
}