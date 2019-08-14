#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 100000

using namespace std;

struct Ponto
{
	int X, Y;

	Ponto(int x, int y)
	{
		X = x;
		Y = y;
	}
};

int main(int argc, char** argv)
{
	// optimize;

	int Q, N, x, y, f1, f2, f3, f4;

	cin >> Q;

	while(Q--)
	{
		cin >> N;

		Ponto a(-MAXN, -MAXN), b(MAXN, MAXN);

		for(int i = 0; i < N; i++)
		{
			cin >> x >> y >> f1 >> f2 >> f3 >> f4;

			if(!f1)
				a.X = max(a.X, x);
			if(!f2)
				b.Y = min(b.Y, y);
			if(!f3)
				b.X = min(b.X, x);
			if(!f4)
				a.Y = max(a.Y, y);
		}
		
		if(a.X <= b.X && a.Y <= b.Y)
			cout << "1 " << a.X << " " << a.Y << endl;
		else 
			cout << 0 << endl;
	}

	return 0;
}
