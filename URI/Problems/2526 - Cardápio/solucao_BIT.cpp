/*
	Solução utilizando BIT
*/
#include <bits/stdc++.h>
#define MAXN 1000100
#define ll unsigned long long

using namespace std;

class BIT{
private:
	int N;
	ll arvore[MAXN];
public:
	BIT(int N){
		this->N = N;
		memset(arvore, 0, sizeof(arvore));
	}

	void add(int posicao, int valor){
		for(; posicao > 0; posicao -= (posicao & -posicao))
			arvore[posicao] += valor;
	}

	ll get(int posicao){
		ll r = 0;

		for(; posicao <= N; posicao += (posicao & -posicao))
			r += arvore[posicao];

		return r;
	}
};

int main(int argc, char const *argv[])
{
	int N, x;

	while((cin >> N)){
		BIT bit(N);

		ll r = 0;

		for (int i = 0; i < N; ++i)
		{
			cin >> x;

			ll maiores = bit.get(x);
			ll menores = x - (i - maiores + 1);

			r += maiores * menores;

			bit.add(x, 1);
		}

		cout << r << endl;
	}
	return 0;
}