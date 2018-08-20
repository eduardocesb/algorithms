#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long

using namespace std;

ll arvore[6 * MAXN];

ll query(int no, int i, int j, int A, int B)
{
	if(i > B || j < A) return 0LL;
	if(A <= i && j <= B) return arvore[no];

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	return ((query(e, i, m, A, B)) | query(d, m + 1, j, A, B));
}

void change(int no, int i, int j, int pos, int v)
{
	if(pos < i || j < pos) return;
	if(i == j)
	{
		arvore[no] = (1LL << v);
		return;
	}

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	change(e, i    , m, pos, v);
	change(d, m + 1, j, pos, v);

	arvore[no] = (arvore[e] | arvore[d]);
}

int main(int argc, char** argv)
{
	int N, Q, M, O, A, B;

	cin >> N >> Q >> M;

	map<int, int> compress;
	int id[MAXN], cont = 0;

	for(int i = 1; i <= N; i++)
	{
		cin >> id[i];
		if(!compress[id[i]])
			compress[id[i]] = ++cont;

		change(1, 1, N, i, compress[id[i]]);
	}

	for(int i = 0; i < Q; i++)
	{
		cin >> O >> A >> B;

		if(O == 1)
			cout << (int)__builtin_popcountll(query(1, 1, N, A, B)) << endl;
		else
		{
			if(!compress[B])
				compress[B] = ++cont;
			change(1, 1, N, A, compress[B]);
		}
	}

	return 0;
}
