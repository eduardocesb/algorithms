/*
	Solução utilizando BIT...
*/
#include <bits/stdc++.h>
#define MAXN 100100

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
		for(; posicao <= N; posicao += (posicao & -posicao))
			arvore[posicao] += valor;
	}

	int get(int posicao){
		int r = 0;

		for(; posicao > 0; posicao -= (posicao & -posicao))
			r += arvore[posicao];

		return r;
	}
};

int main(int argc, char const *argv[])
{
	int N, x;

	char op;

	cin >> N;

	int nums[N + 1];

	BIT bit(N);

	for (int i = 1; i <= N; ++i)
		cin >> nums[i], bit.add(i, nums[i]);

	while((cin >> op >> x)){
		if(op == 'a')
			bit.add(x, nums[x] * -1);
		else
			cout << bit.get(x - 1) << endl;
	}

	return 0;
}