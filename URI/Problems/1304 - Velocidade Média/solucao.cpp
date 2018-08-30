#include <bits/stdc++.h>

using namespace std;

int processa(string x)
{
	return stoi(x.substr(6, 2)) + (stoi(x.substr(3, 2)) * 60) + (stoi(x.substr(0, 2)) * 3600);
}

int main(int argc, char** argv)
{
	string op;

	int ultimo = 0;

	double distancia = 0, velocidade = 0;

	cout << setprecision(2) << fixed;

	while(getline(cin, op))
	{
		int tam = op.length();
		if(tam > 8)
		{
			int atual = processa(op.substr(0, 8));
			distancia += (((atual - ultimo) / 3600.0) * velocidade);

			velocidade = stoi(op.substr(9, tam - 9));
			ultimo = atual;
		}
		else
		{
			int atual = processa(op.substr(0, 8));

			double r = distancia +  (((atual - ultimo) / 3600.0) * velocidade);

			cout << op << " " << r << " km" << endl;
		}
	}

	return 0;
}
