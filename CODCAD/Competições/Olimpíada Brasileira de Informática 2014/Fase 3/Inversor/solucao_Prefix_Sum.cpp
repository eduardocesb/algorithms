/*
	Solução utilizando soma de prefixos...
*/
#include <bits/stdc++.h>
#define INFINITO -10000000000010

using namespace std;

int main(int argc, char const *argv[])
{
	int N, K, x;

	scanf("%d %d", &N, &K);

	long nums[N + 2], best[N + 2];

	//Inicializa as variaveis...	
	for (int i = 0; i <= N + 1; ++i) best[i] = INFINITO, nums[i] = 0;

	//Lê os valores...
	for (int i = 1; i <= N; ++i)
		scanf("%d", &x), nums[i] = nums[i - 1] - x;

	//Para cada possivel intervalo, verifica se é melhor deixar o que já existia ou criar um novo...
	for (int inicio = N - K + 1, fim = N; inicio ; inicio--, fim--)
		best[inicio] = max(best[inicio + 1], nums[fim] - nums[inicio - 1]);
	
	long r = INFINITO;

	//Encontra a melhor soma possivel...
	for (int inicio = 1, fim = K; fim <= N; inicio++, fim++)
		r = max(r, ((nums[fim] - nums[inicio - 1]) + best[fim + 1]));

	printf("%ld\n", r);

	return 0;
}