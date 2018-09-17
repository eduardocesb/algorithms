#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

int r[4][MAXN];

int main(int argc, char** argv)
{
	int N, K;

	scanf("%d %d", &N, &K);

	int meio = N / 2;
	
	//Caso base...
	if(K % 2)
	{
		r[1][meio] = true;
		K--;
	}
	else if(K)
	{
		r[1][meio] = r[2][meio] = true;
		K -= 2;
	}

	//Pinta a linha de cima...
	int k = 1;
	for(; K > 0 && (meio + k < N - 1); k++)
	{
		r[1][meio - k] = r[1][meio + k] = true;
		K -= 2;
	}
	
	//Pinta a linha de baixo...
	k = 1;
	for(; K > 0; k++)
	{
		r[2][meio - k] = r[2][meio + k] = true;
		K -= 2;
	}

	//Printa a resposta...
	puts("YES");
	for(int j = 0; j < 4; j++)
		for(int i = 0; i < N; i++)
			printf("%c%s", (r[j][i] ? '#' : '.'), (i == N - 1 ? "\n" : ""));

	return 0;
}
