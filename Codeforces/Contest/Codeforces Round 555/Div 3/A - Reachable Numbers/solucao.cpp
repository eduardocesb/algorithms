//https://codeforces.com/problemset/problem/1157/A
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 200020
#define MAXL 22

using namespace std;

map<int, int> ok;

int f(int N)
{
	if(ok[N]) return 0;
	ok[N] = true;
	while(!(N % 10)) N /= 10;


	return 1 + f(N + 1);
}

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	cin >> N;

	cout << f(N + 1) << endl;

	return 0;
}