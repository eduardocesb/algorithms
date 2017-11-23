#include <bits/stdc++.h>
#define MAXI 110

using namespace std;

int main(int argc, char const *argv[])
{
	int T, D, I, B, Q;
	int preco[MAXI], custo, indice, quantidade;

	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		scanf("%d %d %d", &D, &I, &B);
		for (int i = 0; i < I; ++i)
			scanf("%d", &preco[i]);

		int r = 0;

		for (int i = 0; i < B; ++i)
		{
			scanf("%d", &Q);
			custo = 0;
			for (int j = 0; j < Q; ++j)
			{
				scanf("%d %d", &indice, &quantidade);
				custo += preco[indice] * quantidade;
			}

			r = max(r, D / custo);
		}

		printf("%d\n", r);
	}

	return 0;
}