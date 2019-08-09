#include <bits/stdc++.h>


using namespace std;

int main(int argc, char const *argv[])
{
	int T, n, s, t;

	cin >> T;

	while(T--)
	{
		cin >> n >> s >> t;

		int diff = (s + t) - n;

		cout << max(s - diff, t - diff) + 1 << endl;
	}

	return 0;
}