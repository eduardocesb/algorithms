/*
	Solução utilizando BIT
*/
#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 100100

using namespace std;

class BIT{
private:
	int N;
	int arvore[MAXN];

public:
	BIT(int N){
		this->N = N;
	}

	void clear(){
		memset(arvore, 0, sizeof(arvore));	
	}

	void add(int posicao, int valor){
		for(; posicao <= N; posicao += (posicao & -posicao))
			arvore[posicao] += valor;
	}

	int get(int posicao){
		int r = 0;

		for(; posicao > 0; posicao -= (posicao & -posicao))
			r+= arvore[posicao];

		return r;
	}
};

int main(int argc, char const *argv[])
{

	optimize;

	int IP, M, PC, NA;
	BIT bit(MAXN);

	while((cin >> IP >> M)){
		int r = 0;

		bit.clear();

		for (int i = 0; i < M; ++i)
		{
			cin >> PC >> NA;
			
			int qtd = bit.get(min(PC + IP, MAXN - 1)) - bit.get(max(0, PC - IP - 1));

			if(qtd <= NA)
				bit.add(PC, 1), r++;

		}

		cout << r << endl;
	}
	return 0;
}