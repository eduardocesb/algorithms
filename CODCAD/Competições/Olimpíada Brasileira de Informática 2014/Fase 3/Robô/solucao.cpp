/*
	Solução utilizando Lazy Propagation
*/
#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 100100

using namespace std;

class Arvore{
private:
	int N;
	bool bloqueado[MAXN * 6];
	bool limpa[MAXN * 6];

	void lazy(int no){
		if(!limpa[no]) return;

		bloqueado[no] = limpa[no] = false;

		int e = 2 * no;
		int d = e + 1;

		limpa[e] = limpa[d] = true;
	}

	void bloqueia(int no, int A, int B, int a, int b){
		lazy(no);

		if(b < A || a > B)
			return;

		if(A >= a && B <= b){
			bloqueado[no] = true;
			return;
		}

		int e = 2 * no;
		int d = e + 1;
		int m = (A + B) / 2;

		bloqueia(e, A    , m, a, b);
		bloqueia(d, m + 1, B, a, b);

		if(bloqueado[e] && bloqueado[d])
			bloqueado[no] = true;
	}

public:
	Arvore(int N){
		this->N = N;
	}

	void bloqueia(int a, int b){
		bloqueia(1, 0, N, a, b);
	}

	void limpar(){
		limpa[1] = true;
	}

	bool bloqueada(){
		return bloqueado[1];
	}
};

int main(int argc, char const *argv[])
{
	optimize;

	int X, Y, a, b, r = 1;

	cin >> Y >> X;

	Arvore arvore(Y);

	arvore.limpar();

	for (int i = 1; i < X; ++i)
	{
		cin >> a >> b;

		arvore.bloqueia(a, b);

		if(arvore.bloqueada()){
			r += 2;
			arvore.limpar();
			arvore.bloqueia(a, b);
		}
	}

	cout << r << endl;
	return 0;
}