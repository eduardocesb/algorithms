#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int N, x, v;

	cin >> N;

	bool ok = true;

	for(int i = 0; i < N; i++)
	{
		cin >> x;

		if(!i) v = x;

		ok *= v >= x;
	}

	cout << (ok ? "S" : "N") << endl;

	return 0;
}