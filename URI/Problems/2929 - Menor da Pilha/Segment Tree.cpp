#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define INFINITO 1000100000
#define MAXN 1001000

using namespace std;

int arvore[6 * MAXN], N;

void update(int no, int i, int j, int p, int v)
{
	if(j < p || i > p) return;
	if(i == j)
	{
		arvore[no] = v;
		return;
	}

	int e = no << 1;
	int d = e | 1;
	int m = (i + j) >> 1;

	update(e, i    , m, p, v);
	update(d, m + 1, j, p, v);

	arvore[no] = min(arvore[e], arvore[d]);
}

int main(int argc, char** argv)
{
	optimize;
	
	cin >> N;

	string op;
	int x, TAM = 1;

	for(int i = 0; i < 6 * MAXN; i++)
		arvore[i] = INFINITO;

	while(N--)
	{
		cin >> op;

		if(op == "PUSH")
		{
			cin >> x;
			update(1, 1, MAXN - 1, TAM++, x);
		}
		else if(op == "POP")
		{
			if(TAM == 1)
				cout << "EMPTY" << endl;
			else
				update(1, 1, MAXN - 1, --TAM, INFINITO);
		}
		else
		{
			if(TAM == 1)
				cout << "EMPTY" << endl;
			else
				cout << arvore[1] << endl;
		}
	}

	return 0;
}
