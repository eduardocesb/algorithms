#include <bits/stdc++.h>
#define MAXN 600000
#define ll unsigned long long int

using namespace std;

ll arvore[MAXN];
ll lazy[MAXN];

void atualiza(int no, int i, int j)
{
	if(!lazy[no]) return;

	int e = 2 * no;
	int d = e + 1;

	arvore[no] += lazy[no] * (j - i + 1);
	lazy[e] += lazy[no];
	lazy[d] += lazy[no];
	lazy[no] = 0;
}

void add(int no, int i, int j, int p, int q, ll v)
{
	atualiza(no, i, j);

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	if(i > j || p > j || q < i) return;

	if(p <= i && j <= q)
	{
		arvore[no] += v * (j - i + 1);
		lazy[e] += v;
		lazy[d] += v;
	}
	else
	{
		add(e, i    , m, p, q, v);
		add(d, m + 1, j, p, q, v);
		arvore[no] = arvore[e] + arvore[d];
	}
}

ll query(int no, int i, int j, int p, int q)
{
	atualiza(no, i, j);
	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	if(i > j || p > j || q < i) return 0LL;
	if(p <= i && j <= q) return arvore[no];
	return query(e, i, m, p, q) + query(d, m + 1, j, p, q);
}


int main(int argc, char const *argv[])
{
	int T, N, C, t, p, q;
	ll v;

	cin >> T;

	while(T--)
	{
		cin >> N >> C;

		memset(arvore, 0, sizeof arvore);
		memset(lazy, 0, sizeof lazy);

		for(int i = 0; i < C; i++)
		{
			cin >> t >> p >> q;

			if(t) cout << query(1, 1, N, p, q) << endl;
			else
			{
				cin >> v;
				add(1, 1, N, p, q, v);
			}
		}
	}

	return 0;
}