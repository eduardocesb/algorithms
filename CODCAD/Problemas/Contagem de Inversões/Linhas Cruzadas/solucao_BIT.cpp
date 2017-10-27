/*
	Solução utilizando a BIT
*/
#include <bits/stdc++.h>
#define MAXN 60060

using namespace std;

class BIT{
private:
	int N;
	int arvore[MAXN];
public:
	BIT(int N){
		this->N = N;
		memset(arvore, 0, sizeof(arvore));
	}

	void add(int posicao, int valor){
		for(; posicao > 0; posicao -= (posicao & -posicao))
			arvore[posicao] += valor;
	}

	int get(int posicao){
		int r = 0;

		for(; posicao <= N; posicao += (posicao & -posicao))
			r += arvore[posicao];
		
		return r;
	}
};

int main(int argc, char const *argv[])
{
	int N, x, r = 0;

	cin >> N;

	BIT bit(N);

	for (int i = 0; i < N; ++i){
		cin >> x;

		r += bit.get(x);

		bit.add(x, 1);
	}

	cout << r << endl;
	return 0;
}