#include <bits/stdc++.h>

using namespace std;

struct Ponto
{
	int X, Y;

	Ponto(){};

	Ponto(int x, int y){
		X = x;
		Y = y;
	}

	Ponto operator - (const Ponto &a){
		return Ponto(X - a.X, Y - a.Y);
	}

	Ponto operator + (const Ponto &a){
		return Ponto(X + a.X, Y + a.Y);
	}

	bool operator < (const Ponto &a) const{
		if(X < a.X) return true;
		if(X == a.X && Y < a.Y) return true;
		return false;
	}
};

int cross(Ponto a, Ponto b){
	return (a.X * b.Y) - (a.Y * b.X);
}

//Calcula a área do fecho convexo...
double area_poligono(vector<Ponto> &p){
	int r = 0;

	for (int i = 2; i < p.size(); ++i)
		r += cross(p[i] - p[0], p[i - 1] - p[0]);

	return r / 2.0;
}

//Checa se posso descartar aquele ponto...
bool check(Ponto &a, Ponto &b, Ponto &c){
	return cross(b - a, c - a) >= 0;
}


//Encontra o fecho convexo...
double convex_hull(vector<Ponto> &p){

	int N = p.size();

	sort(p.begin(), p.end());

	vector<Ponto> pilha;

	pilha.push_back(p[0]);
	int tam = 1;

	for (int i = 1; i < N; ++i)
	{
		while(tam > 1 && check(pilha[tam - 2], pilha[tam - 1], p[i]))
			--tam, pilha.pop_back();

		++tam, pilha.push_back(p[i]);
	}

	int tam_ = tam;

	for (int i = N - 2; i >= 0 ; --i)
	{
		while(tam_ > tam && check(pilha[tam_ - 2], pilha[tam_ - 1], p[i]))
			--tam_, pilha.pop_back();

		++tam_, pilha.push_back(p[i]);
	}

	return area_poligono(pilha);
}

int main(int argc, char const *argv[])
{
	int N;

	while(scanf("%d", &N) == 1){
		vector<Ponto> pontos(N);

		for (int i = 0; i < N; ++i)
			scanf("%d %d", &pontos[i].X, &pontos[i].Y);

		printf("%.2lf\n", convex_hull(pontos));
	}

	return 0;
}