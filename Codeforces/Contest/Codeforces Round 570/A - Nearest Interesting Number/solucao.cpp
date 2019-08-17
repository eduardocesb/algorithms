#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

bool f(int N)
{
	int sum = 0;

	while(N)
	{
		sum += N % 10;
		N /= 10;
	}

	return !(sum % 4);
}

int solve(int N)
{
	return f(N) ? N : solve(N + 1);
}


int main(int argc, char** argv)
{
	optimize;

	int N;

	cin >> N;

	cout << solve(N) << endl;
	
	return 0;
}
