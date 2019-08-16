#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 100010


using namespace std;

int pos[27];

int f(int x)
{
	for(int i = 1; i <= 36; i++)
		if(pos[i] == x) return i;
	return 0;
}

int main(int argc, char** argv)
{
	optimize;

	int N, x, t = 1;

	while((cin >> N) && N)
	{
		for(int i = 1; i <= 26; i++)
			pos[i] = i;

		cout << "Instancia " << t++ << endl;

		for(int i = 0; i < N; i++)
		{
			cin >> x;

			char r = 'A';

			int y = f(x);

			r += y - 1;

			cout << r;

			for(int i = 1; i <= 26; i++)
				if(pos[i] < x)
					pos[i]++;

			pos[y] = 1;
		}

		cout << endl << endl;
	}

	return 0;
}
