#include <bits/stdc++.h>

using namespace std;

struct Ponto{
	long long X, Y;

	Ponto(){};

	bool operator < (const Ponto a)const{
		return X < a.X;
	}
};

//Calcula o determinante...
long long det(Ponto &a, Ponto &b, Ponto &c){
	return 	(c.X * b.Y) + (a.X * c.Y) + (b.X * a.Y) -
			(c.X * a.Y) - (b.X * c.Y) - (a.X * b.Y);
}

int convex_hull(vector<Ponto> &p){
	int N = p.size();

	sort(p.begin(), p.end());

	//Árvores que Obi vai passar...
	vector<Ponto> pulos;

	pulos.push_back(p[0]);

	for (int i = 1; i < N; ++i)
	{
		//Enquanto tiver 2 ou mais pontos e o ângulo formado entre eles for maior que 180º...
		while(pulos.size() > 1 && det(pulos[pulos.size() - 2], pulos[pulos.size() - 1], p[i]) <= 0)
			pulos.pop_back();

		pulos.push_back(p[i]);
	}

	//Retorna o número de árvores menos 1...
	return pulos.size() - 1;
}

int main(int argc, char const *argv[])
{
	int N;

	scanf("%d", &N);

	vector<Ponto> arvores(N);

	for (int i = 0; i < N; ++i)
		scanf("%lld %lld", &arvores[i].X, &arvores[i].Y);

	printf("%d\n", convex_hull(arvores));

	return 0;
}