#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define pii pair<int, int>
#define MAXN 100100

using namespace std;

int K;

char vogais[] = {'a', 'e', 'i', 'o', 'u'};

string solve()
{
	string r = "";

	int n, m;
	bool flag = false;

	for(int i = 5; i < K; i++)
		// if(!(K % i))
		if(!(K % i) && (K / i) > 4)
		{
			n = i;
			m = K / i;
			flag = true;
			break;
		}

	if(!flag) return "-1";

	// cout << n << " " << m << endl;

	int mapa[n][m];

	int atual = 0;


	for(int i = 0; i < m; i++)
		mapa[0][i] = (atual++) % 5;

	for(int i = 1; i < n; i++)
		for(int j = 0; j < m; j++)
			mapa[i][j] = (mapa[i - 1][j] + 1) % 5;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			r += vogais[mapa[i][j]];

	return r;
}


int main(int argc, char** argv)
{
	cin >> K;

	cout << solve() << endl;

	return 0;
}
