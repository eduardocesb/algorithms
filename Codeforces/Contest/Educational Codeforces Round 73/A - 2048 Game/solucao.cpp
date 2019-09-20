#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main(int argc, char** argv)
{

	unordered_map<int, int> mapa;

	int T, N, x;

	cin >> T;

	while(T--)
	{
		cin >> N;

		mapa.clear();

		bool ok = false;

		for(int i = 0; i < N; i++)
		{
			cin >> x;

			mapa[x]++;
		}

		int i = 1;

		while(i <= 2048)
		{
			ok += mapa[2048];
			if(mapa[i] >= 2)
			{
				mapa[2 * i]++;
				mapa[i] -= 2;
			}
			else
				i *= 2;
		}

		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}
