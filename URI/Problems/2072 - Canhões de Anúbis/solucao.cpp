/*
	Solução por Carlos Eduardo
	Canhões de Anúbis - XIV Maratona de Programação IME-USP - 2010
	Dedicado especialmente para meu Professor Iallen Gábio
*/

#include <bits/stdc++.h>
#define MAXN 55

using namespace std;

struct Ponto
{
	int X, Y, Z;

	Ponto(int x = 0, int y = 0, int z = 0)
	{
		X = x;
		Y = y;
		Z = z;
	}

	//Para determinar se um ponto é menor que outro...
	bool operator < (const Ponto a) const
	{
		if(X != a.X) return X < a.X;
		if(Y != a.Y) return Y < a.Y;
		return Z < a.Z;
	}

	//Para realizar a subtração de dois pontos...
	Ponto operator - (const Ponto a) const
	{
		Ponto r(X - a.X, Y - a.Y, Z - a.Z);
		return r;
	}
};

int T, N;
Ponto pontos[MAXN];

//Quantidade de pontos existentes com as mesmas coordenadas...
map<Ponto, int> quantidade;

int determinante(Ponto a, Ponto b, Ponto c);

int solve(int qtd);

int main(int argc, char** argv)
{
	Ponto p;

	scanf("%d", &T);

	for(int t = 0; t < T; t++)
	{
		int qtd = 0;
		quantidade.clear();

		scanf("%d", &N);

		for(int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &p.X, &p.Y, &p.Z);

			//Se o ponto 'p' ainda não existe...
			//Adiciono o mesmo na lista de pontos...
			if(!quantidade[p])
				pontos[qtd++] = p;

			//Aumento a quantidade de vez que o ponto 'p' aparece...
			quantidade[p]++;
		}

		printf("%d\n", solve(qtd));
	}

	return 0;
}

//Função que calcula o determinante de uma matriz 3 x 3...
inline int determinante(Ponto a, Ponto b, Ponto c)
{
	int  diagonal_principal = (a.X * b.Y * c.Z) + (a.Y * b.Z * c.X) + (a.Z * b.X * c.Y);
	int diagonal_secundaria = (a.Z * b.Y * c.X) + (a.X * b.Z * c.Y) + (a.Y * b.X * c.Z);

	return (diagonal_principal - diagonal_secundaria);
}

//Função que verifica se três pontos são colineares...
inline bool colinear(Ponto &a, Ponto &b, Ponto &c)
{
	if (!determinante(Ponto(a.X, a.Y, 1), Ponto(b.X, b.Y, 1), Ponto(c.X, c.Y, 1))
			&& !determinante(Ponto(a.X, a.Z, 1), Ponto(b.X, b.Z, 1), Ponto(c.X, c.Z, 1))
			&& !determinante(Ponto(a.Y, a.Z, 1), Ponto(b.Y, b.Z, 1), Ponto(c.Y, c.Z, 1)))
		return true;
	return false;
}

//Função que verifica se 4 pontos fazem parte do mesmo plano...
//Para isto, verificaremos se o determinante dos vetores AB, AC e AD é '0', caso seja,
//significa que eles fazem parte do mesmo plano...
bool coplanar(Ponto a, Ponto b, Ponto c, Ponto d)
{
	return !determinante(b - a, c - a, d - a);
}

int solve(int qtd)
{
	//Caso base...
	//Sempre é possivel formar um plano que passa por três pontos ou menos...
	if(qtd < 4)
		return N;

	int r = 0;

	//Caso existam mais de três pontos diferentes...
	//Tento montar um plano a partir de três pontos 'i', 'j' e 'k' e em seguida, para cada ponto
	//seguinte, verifico se ele faz parte desse plano...
	for(int i = 0; i < qtd; i++)
	{
		for(int j = i + 1; j < qtd; j++)
		{
			for(int k = j + 1; k < qtd; k++)
			{
				//Número de pontos iguais a 'i' somado ao número de pontos iguais a 'j'
				int da_vez = quantidade[pontos[i]] + quantidade[pontos[j]];

				//Número de pontos 'k' que estão na reta formada pelos pontos 'i' e 'j'...
				//Como para formar um plano precisamos de no minimo três pontos que não estejam na mesma reta
				//'desconsidero' estes, mas sem esquecer de somar a solução local...
				while(k < qtd && colinear(pontos[i], pontos[j], pontos[k]))
					da_vez += quantidade[pontos[k++]];

				//Somo também a quantidade de pontos iguais a 'k'...
				da_vez += quantidade[pontos[k]];

				//Para cada um dos 'l' pontos seguintes...
				//Verifico se ele pertence ao plano formado pelos pontos 'i', 'j' e 'k'
				for(int l = k + 1; l < qtd; l++)
					if(coplanar(pontos[i], pontos[j], pontos[k], pontos[l]))
						da_vez += quantidade[pontos[l]];

				r = max(r, da_vez);
			}
		}
	}

	return r;
}
