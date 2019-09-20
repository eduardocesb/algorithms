#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll unsigned long long

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	ll N;

	cin >> N;

	cout << (1LL << __builtin_popcountll(N)) << endl;
	
	return 0;
}