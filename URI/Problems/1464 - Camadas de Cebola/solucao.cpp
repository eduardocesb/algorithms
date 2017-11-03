	#include <bits/stdc++.h>

	using namespace std;

	struct Ponto{
		int X, Y, i;

		bool operator < (const Ponto a) const{
			if(X <  a.X) return true;
			if(X != a.X) return false;
			if(Y <  a.Y) return true;
			return false;
		}
	};

	//Calcula o determinante...
	int det(Ponto &a, Ponto &b, Ponto &c){
		return 	(c.X * b.Y) + (a.X * c.Y) + (b.X * a.Y) -
				(c.X * a.Y) - (b.X * c.Y) - (a.X * b.Y);
	}

	int convex_hull(vector<Ponto> &p){
		int N = p.size();

		if(N < 3) return 0;

		sort(p.begin(), p.end());

		vector<Ponto> pilha;

		bool remove[N];
		memset(remove, 0, sizeof(remove));

		p[0].i = 0;

		pilha.push_back(p[0]);


		int tam = 1;

		for (int i = 1; i < N; ++i)
		{
			while(tam > 1 && det(pilha[tam - 2], pilha[tam - 1], p[i]) < 0)
				--tam, pilha.pop_back();

			p[i].i = i;
			++tam, pilha.push_back(p[i]);
		}

		int tam_ = tam;

		for (int i = N - 2; i >= 0; --i)
		{
			while(tam_ > tam && det(pilha[tam_ - 2], pilha[tam_ - 1], p[i]) < 0)
				--tam_, pilha.pop_back();

			++tam_, pilha.push_back(p[i]);
		}

		vector<Ponto> r;


		//Marca os pontos a serem removidos...
		for (int j = 0; j < pilha.size(); ++j)
			remove[pilha[j].i] = true;

		for (int j = 0, cont = 0; j < N; ++j)
			if(!remove[j])
				r.push_back(p[j]);

		return 1 + convex_hull(r);
	}

	int main(int argc, char const *argv[])
	{
		int N;

		while(scanf("%d", &N) && N){
			vector<Ponto> pontos(N);

			for (int i = 0; i < N; ++i)
				scanf("%d %d", &pontos[i].X, &pontos[i].Y);

			if(convex_hull(pontos) % 2)
				puts("Take this onion to the lab!");
			else
				puts("Do not take this onion to the lab!");
		}

		return 0;
	}