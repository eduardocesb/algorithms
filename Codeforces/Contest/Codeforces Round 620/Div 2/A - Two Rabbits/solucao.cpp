//https://codeforces.com/contest/1304/problem/A
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 2000020

using namespace std;


int main(int argc, char const *argv[])
{
	optimize;

	int T, A, B, X, Y;

	cin >> T;

	while(T--)
	{
		cin >> A >> B >> X >> Y;

		int N = B - A;

		if(N % (X + Y)) cout << -1 << endl;
		else cout << (N / (X + Y)) << endl;
	}

	return 0;
}