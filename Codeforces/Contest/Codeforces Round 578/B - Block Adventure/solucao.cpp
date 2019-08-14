#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	int N, Q, M, K;

	cin >> Q;

	while(Q--)
	{
		cin >> N >> M >> K;

		int ant = 0, x = 0;

		bool ok = true;

		for(int i = 0; i < N; i++)
		{
			ant = x;

			cin >> x;

			if(!i) continue;

			if(ant + K > x)
				M += ant - max(x - K, 0);
			else
				M -= x - (ant + K);

			if(M < 0) ok = false;
		}

		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}
