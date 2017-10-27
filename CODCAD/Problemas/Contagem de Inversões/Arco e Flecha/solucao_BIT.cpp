#include <bits/stdc++.h>
#define MAXN 100100
#define ll long long

using namespace std;

int N;

class BIT{
private:
	ll arvore[MAXN];
	int N;
public:
	BIT(int N){
		this->N = N;
		memset(arvore, 0, sizeof(arvore));
	}

	void add(int posicao, int valor){
		for (; posicao <= N; posicao += (posicao & -posicao))
			arvore[posicao] += valor;
	}

	ll get(int posicao){
		ll r = 0;

		for (; posicao > 0 ; posicao -= (posicao & - posicao))
			r += arvore[posicao];

		return r;
	}
};

ll distancia[MAXN];
map<ll, int> mapa;

void compress(){
	for (int i = 0; i < N; ++i)
		mapa[distancia[i]] = 0;

	map<ll, int>::iterator it = mapa.begin();

	int cont = 1;

	for(; it != mapa.end(); it++)
		it->second = cont++;
}

int main(int argc, char const *argv[])
{

	ll x, y;

	cin >> N;

	BIT bit(N);

	for (int i = 0; i < N; ++i)
		cin >> x >> y, distancia[i] = (x * x) + (y * y);

	compress();

	ll r = 0;

	for (int i = 0; i < N; ++i)
		r += bit.get(mapa[distancia[i]]), bit.add(mapa[distancia[i]], 1);

	cout << r << endl;
	return 0;
}