#include <iostream>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		unordered_map<string, double> precos;
		for (int i = 0; i < x; ++i)
		{
			string produto;
			double preco;
			cin >> produto >> preco;
			precos[produto] = preco;
		}
		cin >> x;
		double r = 0;
		for (int i = 0; i < x; ++i)
		{
			string produto;
			int qtd;
			cin >> produto >> qtd;
			r += precos[produto] * qtd;
		}

		printf("R$ %.2f\n", r);
	}
	return 0;
}