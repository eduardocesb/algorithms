#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	string N;

	cin >> N;

	reverse(N.begin(), N.end());

	cout << N << endl;

	return 0;
}