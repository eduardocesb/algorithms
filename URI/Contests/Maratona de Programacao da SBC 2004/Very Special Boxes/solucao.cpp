#include <bits/stdc++.h>
#define INFINITO 1000000000

using namespace std;

struct Caixa
{
	int X, Y, Z;

	Caixa(int a = 0, int b = 0, int c = 0)
	{
		if(c < a) swap(c, a);
		if(c < b) swap(c, b);
		if(b < a) swap(b, a);

		X = a, Y = b, Z = c;
	}

	bool operator < (const Caixa a) const
	{
		if(X != a.X) return X < a.X;
		if(Y != a.Y) return Y < a.Y;
		return Z < a.Z;
	}

	int operator - (const Caixa a)const
	{
		return (X * Y * Z) - (a.X * a.Y * a.Z);
	}
};

map<Caixa, int> caixas;

bool cabe(Caixa a, Caixa b)
{
	return (a.X <= b.X && a.Y <= b.Y && a.Z <= b.Z);
}

int main(int argc, char** argv)
{
	int N, M, X, Y, Z;

	while(scanf("%d %d", &N , &M) && (N || M))
	{
		caixas.clear();

		scanf("%d %d %d", &X, &Y, &Z);

		Caixa alfa(X, Y, Z);

		for(int i = 0; i < M; i++)
		{
			scanf("%d %d %d", &X, &Y, &Z);
			caixas[Caixa(X, Y, Z)]++;
		}

		int r = INFINITO;
		
		for(auto c : caixas)
			if(cabe(alfa, c.first) && c.second >= N)
				r = min(r, c.first - alfa);
 
		if(r == INFINITO)
			puts("impossible");
		else
			printf("%d\n", r);
	}

	return 0;
}
