#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char** argv)
{
	optimize;
	int N, T, Q, op, x, y;

	cin >> T;

	while(T--)
	{
		cin >> N;

		bitset<61> conjuntos[N + 1];

		for(int i = 1; i <= N; i++)
		{
			cin >> Q;

			while(Q--)
			{
				cin >> x;
				conjuntos[i][x] = 1;
			}
		}

		cin >> Q;

		bitset<61> aux;

		while(Q--)
		{
			cin >> op >> x >> y;

			if(op == 1)
				aux = (conjuntos[x]) & (conjuntos[y]);
			else
				aux = conjuntos[x] | conjuntos[y];

			cout << aux.count() << endl;
		}
	}

	return 0;
}
