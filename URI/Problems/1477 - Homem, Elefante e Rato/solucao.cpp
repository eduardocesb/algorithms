#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

struct pii
{
	int h, e, r;

	pii()
	{
		h = e = r = 0;
	}

	pii(int a, int b, int c)
	{
		h = a;
		e = b;
		r = c;
	}

	pii operator + (const pii p)const
	{
		return pii(p.h + h, p.e + e, p.r + r);
	}

	void add()
	{
		swap(h, e);
		swap(h, r);
	}
};

pii arvore[6 * MAXN];
int lazy[6 * MAXN];

void build(int no, int i, int j)
{
	if(i > j) return;

	if(i == j)
	{
		arvore[no] = pii(1, 0, 0);
		return;
	}

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	build(e, i, m);
	build(d, m + 1, j);

	arvore[no] = arvore[e] + arvore[d];
}

void update(int no)
{
	if(!lazy[no]) return;

	int e = 2 * no;
	int d = e + 1;
	int x = lazy[no] % 3;

	lazy[e] += lazy[no];
	lazy[d] += lazy[no];
	lazy[no] = 0;

	while(x--)
		arvore[no].add();
}

void add(int no, int i, int j, int A, int B)
{
	update(no);

	if(j < A || i > B) return;
	if(A <= i && j <= B)
	{
		lazy[no]++;
		update(no);
		return;
	}

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	add(e,     i, m, A, B);
	add(d, m + 1, j, A, B);

	arvore[no] = arvore[e] + arvore[d];
}


pii query(int no, int i, int j, int A, int B)
{
	update(no);
	if(i > B || j < A) return pii();
	if(A <= i && j <= B)
		return arvore[no];

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	return query(e, i, m, A, B) + query(d, m + 1, j, A, B);
}


int main(int argc, char** argv)
{
	int N, M, A, B;
	char op;

	while(scanf("%d %d", &N, &M) == 2)
	{
		memset(arvore, 0, sizeof(arvore));
		memset(lazy, 0, sizeof(lazy));

		build(1, 1, N);

		for(int i = 0; i < M; i++)
		{
			scanf(" %c %d %d", &op, &A, &B);

			if(op == 'M') add(1, 1, N, A, B);
			else
			{
				pii r = query(1, 1, N, A, B);
				printf("%d %d %d\n", r.h, r.e, r.r);
			}
		}

		puts("");
	}


	return 0;
}
