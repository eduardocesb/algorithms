#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define MAXN 100100

using namespace std;

ll arvore[6 * MAXN];
ll lazy[6 * MAXN];
int nums[MAXN];

void up(int no, int i, int j)
{
	int e = no << 1;
	int d = e | 1;
	int tam = (j - i) + 1;

	if(!lazy[no]) return;

	lazy[e] += lazy[no];
	lazy[d] += lazy[no];

	arvore[no] += tam * lazy[no];
	lazy[no] = 0;
}

void update(int no, int i, int j, int A, int B, int v)
{
	up(no, i, j);

	if(i > j || j < A || i > B)
		return;

	if(A <= i && j <= B)
	{
		lazy[no] += v;
		up(no, i, j);
		return;
	}

	int e = no << 1;
	int d = e | 1;
	int m = (i + j) >> 1;

	update(e, i    , m, A, B, v);
	update(d, m + 1, j, A, B, v);

	arvore[no] = arvore[e] + arvore[d];
}

ll query(int no, int i, int j, int A, int B)
{
	up(no, i, j);

	if(j < i || j < A || i > B) return 0LL;
	if(A <= i && j <= B) return arvore[no];

	int e = no << 1;
	int d = e | 1;
	int m = (i + j) >> 1;

	return query(e, i, m, A, B) + query(d, m + 1, j, A, B);
}

int main(int argc, char** argv)
{
	optimize;
	int T, N, C, op, p, q, v;

	scanf("%d", &T);

	while(T--)
	{
		memset(arvore, 0, sizeof(arvore));
		memset(lazy, 0, sizeof(lazy));

		scanf("%d %d", &N, &C);

		for(int i = 0; i < C; i++)
		{
			scanf("%d %d %d", &op, &p, &q);

			if(op)
				printf("%ld\n", query(1, 1, N, p, q));
			else
			{
				scanf("%d", &v);
				update(1, 1, N, p, q, v);
			}
		}
	}
	return 0;
}
