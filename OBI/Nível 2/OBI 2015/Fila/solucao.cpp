#include <bits/stdc++.h>
#define MAXK 800

using namespace std;

struct Bloco
{
	int maior_altura, tam;

	Bloco()
	{
		tam = maior_altura = 0;
	}

	vector<int> alturas;

	void inserir(int h, int i)
	{
		if(h > maior_altura)
			maior_altura = h;

		alturas.insert(alturas.begin() + i, h);
		tam++;
	}

	pair<Bloco, Bloco> divide()
	{
		Bloco a, b;

		for (int i = 0, j = 0; i < tam; ++i)
			if(2 * i < tam)
				a.inserir(alturas[i], i);
			else
				b.inserir(alturas[i], j++);

		return make_pair(a, b);
	}

	int maior(int H, int i)
	{
		for(int j = i; j >=0 ; j--)
			if(alturas[j] > H)
				return j + 1;

		return -1;
	}

	int indice(int H)
	{
		for (int i = tam; i ; --i)
			if(alturas[i - 1] > H)
				return i;
	}
};

struct Blocos
{
	vector<Bloco> blocos;

	Blocos()
	{
		blocos.push_back(Bloco());
	}

	void add(int h, int i)
	{
		int j = 0;

		for (; j < (int)blocos.size(); ++j)
			if(blocos[j].tam < i)
				i -= blocos[j].tam;
			else
				break;

		blocos[j].inserir(h, i);

		if(blocos[j].tam >= 2 * MAXK){
			pair<Bloco, Bloco> r = blocos[j].divide();

			blocos.erase(blocos.begin() + j);

			blocos.insert(blocos.begin() + j, r.second);
			blocos.insert(blocos.begin() + j, r.first);
		}
	}

	int query(int D, int i)
	{
		int j = 0;

		int quantidade = 0;

		for (; j < (int)blocos.size(); ++j)
		{
			if(blocos[j].tam < i)
			{
				quantidade += blocos[j].tam;
				i -= blocos[j].tam;
			}
			else
				break;
		}

		int H = blocos[j].alturas[i - 1] + D;

		int x = blocos[j].maior(H, i - 1);

		if(x != -1)
			return quantidade + x;

		for (int k = j - 1; k >= 0 ; k--)
		{
			quantidade -= blocos[k].tam;

			if(blocos[k].maior_altura > H)
			{
				return quantidade + blocos[k].indice(H);
			}
		}

		return -1;
	}
};

int main(int argc, char const *argv[])
{
	Blocos nums;

	int N, H, Q, I, O, X;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &H), nums.add(H, i);

	scanf("%d", &Q);

	for (int i = 0; i < Q; ++i)
	{
		scanf("%d %d %d", &O, &I, &X);
		if(O){
			int x = nums.query(X, I);
			if(x != -1)
				printf("%d\n", nums.query(X, I));
			else
				puts("0");
		}
		else
			nums.add(X, I);
	}


	return 0;
}