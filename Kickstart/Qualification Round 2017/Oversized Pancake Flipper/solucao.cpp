#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MN 1010

using namespace std;

int dp[MN];

int main(int argc, char** argv)
{
	optimize;
	int N, r = 0, K;
	string x;

	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		cin >> x >> K;
		r = 0;
		int tam = x.length();

		for(int j = 0; j < tam; j++)
			dp[j] = x[j] == '+';

		for(int j = 0; j <= tam - K; j++)
		{
			if(dp[j]) continue;
			r++;

			for(int k = j; k < j + K; k++)
				dp[k] = !dp[k];
		}

		bool ok = true;

		for(int j = 0; j < tam; j++)
			ok *= dp[j];

		cout << "Case #" << i << ": ";

		if(ok)
			cout << r << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
