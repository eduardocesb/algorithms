#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define INFINITO 1000000010
#define MAXN 2000020
#define pii pair<int, int>

using namespace std;

int primos[MAXN], bit[MAXN];

void crivo()
{
	for(int i = 1; i < MAXN; i++)
		for(int j = i; j < MAXN; j += i)
			primos[j]++;
}

void add(int idx)
{
	for(; idx < MAXN; idx += (idx & -idx))
		bit[idx]++;
}

int query(int idx)
{
	int r = 0;

	for(; idx > 0; idx -= (idx & -idx))
		r += bit[idx];

	return r;
}

void precalc()
{
	crivo();

	for(int i = 2; i < MAXN; i++)
		if(primos[primos[i]] == 2)
			add(i);
}

int main(int argc, char const *argv[])
{
	optimize;
	precalc();

	int N;

	while(!cin.eof() && (cin >> N))
		cout << query(N) << endl;

	return 0;
}