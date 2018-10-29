#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 100100

using namespace std;

int arvore[MAXN * 6];
int nums[MAXN], v[MAXN], N, Q;

void build(int no, int i, int j)
{
	if(i == j)
	{
		arvore[no] = v[i];
		return;
	}

	int e = no << 1;
	int d = e + 1;
	int m = (i + j) >> 1;

	build(e, i, m);
	build(d, m + 1, j);

	arvore[no] = max(arvore[e], arvore[d]);
}

void update(int no, int i, int j, int u, int k)
{
	if(i > u || j < u || i > j) return;
	if(i == j)
	{
		arvore[no] = k;
		return ;
	}

	int e = no << 1;
	int d = e + 1;
	int m = (i + j) >> 1;

	update(e, i, m, u, k);
	update(d, m + 1, j, u, k);

	arvore[no] = max(arvore[e], arvore[d]);
}

int query(int no, int i, int j, int a, int b)
{
	if(i > b || j < a || i > j) return 0;

	if(a <= i && j <= b) return arvore[no];

	int e = no << 1;
	int d = e + 1;
	int m = (i + j) >> 1;

	return max(query(e, i, m, a, b), query(d, m + 1, j, a, b));
}

int binary_search(int i, int h)
{
	int inicio = 1, fim = i, meio, R = i, L = i;

	while(inicio <= fim)
	{
		meio = (inicio + fim) >> 1;

		if(query(1, 1, N - 1, meio, i - 1) <= h)
			fim = meio - 1, L = meio;
		else
			inicio = meio + 1;
	}

	inicio = i, fim = N - 1;

	while(inicio <= fim)
	{
		meio = (inicio + fim) >> 1;

		if(query(1, 1, N - 1, i, meio) <= h)
			R = inicio = meio + 1;
		else
			fim = meio - 1;
	}

	return (R - L) + 1;
}

int main(int argc, char** argv)
{
	optimize;

	cin >> N >> Q;

	for(int i = 1; i <= N; i++) cin >> nums[i];

	for(int i = 1; i < N; i++) v[i] = abs(nums[i] - nums[i + 1]);

	build(1, 1, N - 1);

	int op, i, h;

	while(Q--)
	{
		cin >> op >> i >> h;

		if(op == 1)
		{
			nums[i] = h;

			update(1, 1, N - 1, i, abs(nums[i + 1] - nums[i]));
			update(1, 1, N - 1, i - 1, abs(nums[i - 1] - nums[i]));
		}
		else
			cout << binary_search(i, h) << endl;
	}

	return 0;
}
