#include <bits/stdc++.h>
#define INFINITO 120000000

using namespace std;

vector<int> primos;
int posicao, r, qtd = 0;

void crivo(int N)
{
	bool primo[N + 1];
	memset(primo, true, sizeof(primo));
 
	for (int i = 2; i < N; i++)
	{
		if (primo[i])
		{
			qtd++;
			if(qtd == posicao){
				r = i;
				return;
			}
			primos.push_back(i);
			for (int j = 2 * i;  j < N; j += i)
				primo[j] = false;
		}
	}
}
 
void crivo_segmentado(int N)
{
	int limite = floor(sqrt(N))+1; 
	crivo(limite); 

	if(qtd == posicao) return;

	int low  = limite;
	int high = 2 * limite;
	int tam = primos.size();

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

		for (int i = low; i < high; i++)
			if (primo[i - low]){
				qtd++;
				if(qtd == posicao){
					r = i;
					return;
				}
			}
			
		low  += limite;
		high += limite;
		if (high >= N) high = N;
	}
}
int main()
{
	cin >> posicao;
	crivo_segmentado(INFINITO);
	cout << r << endl;
	return 0;
}