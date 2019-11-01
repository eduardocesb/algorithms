#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 100100
#define MAXL 22

using namespace std;

int MDC(int a, int b)
{
	return !b ? a : MDC(b, a % b);
}

int main(int argc, char const *argv[])
{
	optimize;

	int T, A, B;


	cin >> T;

	while(T--)
	{
		cin >> A >> B;

		cout << (MDC(A, B) == 1 ? "Finite" : "Infinite") << endl;
	}

	return 0;
}