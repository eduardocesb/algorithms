#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 100100
#define MAXL 22

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int T, N, X, A, B;

	cin >> T;

	while(T--)
	{
		cin >> N >> X >> A >> B;

		cout << min(N - 1, abs(A - B) + X) << endl;
	}
	
	return 0;
}
