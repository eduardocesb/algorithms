#include <bits/stdc++.h>
#define MAXN 10000000
#define ull unsigned long long

using namespace std;

ull call = 0;

ull fib(int x){
	call++;
	if(x < 2) return x;

	return fib(x - 1) + fib(x - 2);
}

int main(int argc, char const *argv[])
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		call = -1;
		ull r = fib(x);

		cout << "fib(" << x << ") = " << call << " calls = " << r << endl;
	}
	return 0;
}