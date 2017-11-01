#include <bits/stdc++.h>

using namespace std;

struct Ponto{
	int X, Y;

	bool operator < (const Ponto & p) const{
		if(p.X < X) return true;
		else if(p.X != X) return false;
		else if(p.Y < Y) return true;
		return false;
	}
};

//Retorna a distancia entre dois pontos...
double distancia(Ponto &a, Ponto &b){
	return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

//Calcula o determinante...
int det(Ponto &a, Ponto &b, Ponto &c){
	return 	(c.X * b.Y) + (a.X * c.Y) + (b.X * a.Y) -
			(c.X * a.Y) - (b.X * c.Y) - (a.X * b.Y);
}

double convex_hull(vector<Ponto> &p, int N){
	double r = 0.0;

	sort(p.begin(), p.end());

	vector<Ponto> pilha;
	int tam = 1;

	//Adiciono o primeiro ponto...
	pilha.push_back(p[0]);

	//Encontro a parte de baixo do casco...
	for (int i = 1; i < N; ++i)
	{
		while(pilha.size() > 1 && det(pilha[tam - 2], pilha[tam - 1], p[i]) <= 0)
			--tam, pilha.pop_back();
		tam++;
		pilha.push_back(p[i]);
	}

	int tam_ = tam;

	//Encontro a parte de cima do casco...
	for (int i = N - 2; i >= 0; --i)
	{
		while(pilha.size() > tam && det(pilha[tam_ - 2], pilha[tam_ - 1], p[i]) <= 0)
			--tam_, pilha.pop_back();
		tam_++;
		pilha.push_back(p[i]);
	}

	//Calculo a distancia entre todos os pontos...
	for (int i = 1; i < pilha.size(); ++i)
		r += distancia(pilha[i], pilha[i - 1]);

	return r;
}

int main(int argc, char const *argv[])
{
	int N;

	while(scanf("%d", &N) && N){

		vector<Ponto> pontos(N);

		for (int i = 0; i < N; ++i)
			scanf("%d %d", &pontos[i].X, &pontos[i].Y);

		printf("Tera que comprar uma fita de tamanho %.2lf.\n", convex_hull(pontos, N));
	}

	return 0;
}