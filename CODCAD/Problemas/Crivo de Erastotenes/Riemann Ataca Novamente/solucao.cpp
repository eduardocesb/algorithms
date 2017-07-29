#include <bits/stdc++.h>
#define MAXN 3000010

using namespace std;

int procurado, posicao = 1;
unordered_map<int, int> posicao_primo;
int primos[MAXN];
void crivo(int N){
	bool primo[N + 1];
	memset(primo, true, sizeof(primo));
	for (int i = 2; i <= N; ++i)
	{
		if(!primo[i]) continue;
		primos[posicao - 1] = i;
		posicao_primo[i] = posicao++;
		for(int j = 2 * i; j <= N; j += i) primo[j] = false;
	}
}

int crivo_segmentado(int N){
	int limite = floor(sqrt(N)) + 1;
	crivo(limite);
	int low = limite;
	int high = 2 * limite;
	int tam = posicao - 1;

	while (low < N)
	{
		bool primo[limite + 1];
		memset(primo, true, sizeof(primo));
		for (int i = 0; i < tam; i++)
		{
			int loLim = floor(low/primos[i]) * primos[i];
			if (loLim < low)
				loLim += primos[i];

			for (int j = loLim; j < high; j += primos[i])
				primo[j-low] = false;
		}

		for (int i = low; i < high; ++i){
			if(primo[i - low])
				posicao_primo[i] = posicao++;
		}
		low += limite;
		high += limite;
		if(high > N) high = N;
	}
}
int main(int argc, char const *argv[])
{
	crivo_segmentado(MAXN);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> procurado;
		cout << posicao_primo[procurado] << endl;
	}
	return 0;
}