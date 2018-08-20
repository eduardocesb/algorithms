#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int arvore[6 * MAXN];
int lazy[6 * MAXN];

void lazy_(int no, int i, int j)
{
	if(lazy[no] == -1) return;

	int e = 2 * no;
	int d = e + 1;

	if((j - i + 1) % 2)
		arvore[no] = lazy[no];
	else
		arvore[no] = 0;

	lazy[e] = lazy[d] = lazy[no];

	lazy[no] = -1;
}

void change(int no, int i, int j, int A, int B, int v)
{
	lazy_(no, i, j);

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	if(B < i || j < A) return;
	if(A <= i && j <= B)
	{
		lazy[no] = v;
		lazy_(no, i, j);
		return;
	}

	change(e, i    , m, A, B, v);
	change(d, m + 1, j, A, B, v);
	arvore[no] = arvore[e] ^ arvore[d];
}

int main(int argc, char** argv)
{
	int N, Q, X, Y, V;
	memset(lazy, -1, sizeof lazy);

	cin >> N >> Q;

	for(int i = 1; i <= N; i++)
	{
		cin >> V;

		change(1, 1, N, i, i, V);
	}

	for(int i = 0; i < Q; i++)
	{
		cin >> X >> Y >> V;
		change(1, 1, N, X, Y, V);

		cout << (arvore[1] ? "Possivel" : "Impossivel") << endl;
	}

	return 0;
}
