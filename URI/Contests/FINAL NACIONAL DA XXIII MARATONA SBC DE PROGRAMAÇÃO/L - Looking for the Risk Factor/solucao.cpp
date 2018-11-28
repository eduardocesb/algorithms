#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int primos[MAXN];
int r[MAXN];
int Q;

void crivo()
{
	memset(primos, -1, sizeof primos);

	for(int i = 2; i < MAXN; i++)
		if(primos[i] == -1)
			for(int j = i; j < MAXN; j += i)
				primos[j] = i;
}

struct Querie
{
	int N, K, i;
	
	bool operator < (const Querie &a) const
	{
		return N < a.N;
	}
} queries[MAXN];

int bit[MAXN];

void add(int i)
{
	for(; i < MAXN; i += (i & -i))
		bit[i]++;
}

int query(int i)
{
	int r = 0;
	for(; i > 0; i -= (i & -i))
		r += bit[i];
	
	return r;
}

void solve()
{
	crivo();
	sort(queries, queries + Q);
	
	memset(bit, 0, sizeof bit);
	
	int cont = 2;
	
	for(int i = 0; i < Q; i++)
	{
		//Atualiza a bit...
		while(cont <= queries[i].N) add(primos[cont++]);
		
		r[queries[i].i] = query(queries[i].K);
	} 
}

int main(int argc, char** argv)
{
	cin >> Q;
	
	for(int i = 0; i < Q; i++)
	{
		cin >> queries[i].N >> queries[i].K;
		queries[i].i = i;
	}
	
	solve();
	
	for(int i = 0; i < Q; i++)
		cout << r[i] << endl;
			
	return 0;
}
