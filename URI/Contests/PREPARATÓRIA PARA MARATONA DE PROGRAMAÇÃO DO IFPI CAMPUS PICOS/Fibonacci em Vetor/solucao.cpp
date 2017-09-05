#include <bits/stdc++.h>
#define ull unsigned long long
#define MAXN 10000000

using namespace std;

ull dp[MAXN];

ull fib(int x){
	if(x < 2) return x;
	if(dp[x] != -1) return dp[x];

	return dp[x] = fib(x - 1) + fib(x - 2);
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < MAXN; ++i) dp[i] = -1;

	ull n, x;
	cin >> n;
	for (ull i = 0; i < n; ++i)
	{
		cin >> x;
		cout << "Fib(" << x << ") = " << fib(x) << endl;
	}
	return 0;
}